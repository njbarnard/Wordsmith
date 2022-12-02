//
// Created by Noah Barnard on 11/30/22.
//

#ifndef WORDSMITH_MAINWINDOW_H
#define WORDSMITH_MAINWINDOW_H

#include <wx/wx.h>

class mainWindow : public wxFrame {

public:
    mainWindow();
    ~mainWindow();

public:

    int nFieldWidth = 10;
    int nFieldHeight = 10;
    wxButton **btn;

    int *nField = nullptr;
    bool bFirstClick = true;

    /*
    wxButton* m_btn1 = nullptr;
    wxTextCtrl* m_txt1 = nullptr;
    wxListBox *m_list1 = nullptr;
    */

    void OnButtonClicked(wxCommandEvent &evt);

    wxDECLARE_EVENT_TABLE();
};


#endif //WORDSMITH_MAINWINDOW_H
