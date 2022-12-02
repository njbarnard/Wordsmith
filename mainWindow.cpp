//
// Created by Noah Barnard on 11/30/22.
//

#include "mainWindow.h"

wxBEGIN_EVENT_TABLE(mainWindow, wxFrame)
    EVT_BUTTON(10001, mainWindow::OnButtonClicked)
wxEND_EVENT_TABLE()

mainWindow::mainWindow() : wxFrame(nullptr, wxID_ANY, "Wordsmith",
                                   wxPoint(30,30), wxSize(800,600)) {

    btn = new wxButton*[nFieldWidth * nFieldHeight];
    wxGridSizer *grid = new wxGridSizer(nFieldWidth, nFieldHeight, 0, 0);

    nField = new int[nFieldWidth * nFieldHeight];

    wxFont font(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);

    for (int y = 0; y < nFieldWidth; y++){
        for (int x = 0; x < nFieldHeight; x++){
            btn[y*nFieldWidth + x] = new wxButton(this, 10000 + (y * nFieldWidth + x));
            btn[y*nFieldWidth + x]->SetFont(font);
            grid->Add(btn[y*nFieldWidth + x], 1, wxEXPAND | wxALL);

            btn[y*nFieldWidth + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &mainWindow::OnButtonClicked, this);
            nField[y*nFieldWidth + x] = 0;
        }
    }

    this->SetSizer(grid);
    grid->Layout();

    /*
    m_btn1 = new wxButton(this, 10001, "Click Me",
                          wxPoint(10,10), wxSize(150,50));
    m_txt1 = new wxTextCtrl(this, wxID_ANY, "",
                          wxPoint(10,70), wxSize(300,30));
    m_list1 = new wxListBox(this, wxID_ANY,
                            wxPoint(10,110), wxSize(300,300));
    */

}

mainWindow::~mainWindow(){
    delete[] btn;
}

void mainWindow::OnButtonClicked(wxCommandEvent &evt){

    int x = (evt.GetId() - 10000) % nFieldWidth;
    int y = (evt.GetId() - 10000) / nFieldWidth;

    if (bFirstClick){
        int mines = 30;

        while (mines){
            int rx = rand() % nFieldWidth;
            int ry = rand() % nFieldHeight;

            if (nField[ry * nFieldWidth + rx] == 0 && rx != x && ry != y){
                nField[ry * nFieldWidth + rx] = -1;
                mines--;
            }
        }
    }

    bFirstClick = false;

    btn[y*nFieldWidth + x]->Enable(false);

    if (nField[y*nFieldWidth + x] == -1){
        wxMessageBox("BOOOOOOM! Game Over");

        //Reset Game
        for (int y1 = 0; y1 < nFieldWidth; y1++){
            for (int x1 = 0; x1 < nFieldHeight; x1++){
                nField[y1*nFieldWidth + x1] = 0;
                btn[y1*nFieldWidth + x1]->SetLabel("");
                btn[y1*nFieldWidth + x1]->Enable(true);
            }
        }
    } else{
       int mine_count = 0;
       for (int i = -1; i < 2; i++){
           for (int j = -1; j < 2; j++){
               if (x + i >= 0 && i <nFieldWidth && y + j >= 0 && y + j < nFieldHeight){
                   if (nField[(y + j)*nFieldWidth + (x + 1)] == -1) mine_count++;
               }
           }
       }
       if (mine_count > 0) btn[y*nFieldWidth + x]->SetLabel(std::to_string(mine_count));
    }

    evt.Skip();

    /*
    m_list1 -> AppendString(m_txt1->GetValue());
    evt.Skip();
    */
}
