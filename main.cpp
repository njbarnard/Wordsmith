// wxWidgets "Hello World" Program

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#include <iostream>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#include "mainWindow.h"
#endif

wxFont startsWithFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTSTYLE_NORMAL);

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);

class MyFrame : public wxFrame{

public:
    MyFrame (const wxString &title, const wxPoint &pos, const wxSize &size);
    void OnType(wxCommandEvent &);
    void CreateGUI();
    void CombineSizers();
    void BindEvents();

private:
    wxSizer *main_sizer, *top_banner_sizer, *body_sizer, *left_column_sizer, *middle_column_sizer,
    *right_column_sizer, *middle_top_sizer, *middle_second_sizer, *middle_left_sizer, *middle_right_sizer,
    *middle_bottom_chunk_sizer, *middle_right_top_sizer, *middle_right_bottom_sizer;

    wxPanel *banner, *metronome, *output, *generate, *startsWith, *endsWith, *contains, *letters, *anagram,
    *length, *syllables, *rhymesWith, *wordType, *checkBoxes, *homophone, *omitLetters, *synonym, *antonym,
    *wordList;

    wxTextCtrl *startsWithField, *endsWithField, *containsField, *lettersField, *lengthField, *syllablesField,
    *rhymesWithField, *homophoneField, *omitLettersField, *synonymField, *antonymField, *outputField;

    bool startsWithIsUsed, endsWithIsUsed, containsIsUsed, lettersIsUsed, anagramIsUsed, lengthIsUsed,
    syllablesIsUsed, rhymesWithIsUsed, wordTypeIsUsed, palindromeIsUsed, kangarooWordIsUsed, compoundWordIsUsed,
    properNounIsUsed, homophoneIsUsed, omitLettersIsUsed, synonymIsUsed, antonymIsUsed;

};

enum ButtonId
{
    bannerID = wxID_LAST + 1, metronomeID, outputID, generateID, startsWithID, endsWithID,
    containsID, lettersID, anagramID, lengthID, syllablesID, rhymesWithID, wordTypeID, checkBoxesID,
    homophoneID, omitLettersID, synonymID, antonymID, wordListID
};

bool MyApp::OnInit() {
    MyFrame *frame = new MyFrame("Wordsmith", wxDefaultPosition, wxDefaultSize);
    frame->Show(true);
    return true;
}

MyFrame::MyFrame (const wxString &title, const wxPoint &pos, const wxSize &size): wxFrame(nullptr, wxID_ANY, title, pos, size){

    CreateGUI();
    CombineSizers();
    BindEvents();

}

void MyFrame::BindEvents(){
    startsWithField->Bind(wxEVT_TEXT, &MyFrame::OnType, this);
}

void MyFrame::CreateGUI() {
    main_sizer = new wxBoxSizer (wxVERTICAL);

    //main_sizer contains
    top_banner_sizer = new wxBoxSizer (wxHORIZONTAL);
    body_sizer = new wxBoxSizer (wxHORIZONTAL);

    //top_banner contains
    banner = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    banner->SetBackgroundColour (wxColor(239, 90, 103));

    /** TEXT LABEL **/
    auto bannerLabel = new wxStaticText(banner, wxID_ANY, "Wordsmith");
    wxFont bannerFont(100, wxFONTFAMILY_DECORATIVE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    bannerLabel->SetFont(bannerFont);
    auto bannerPanelSizer = new wxBoxSizer(wxVERTICAL);
    bannerPanelSizer->Add(bannerLabel, 1, wxALIGN_CENTER_HORIZONTAL);
    banner->SetSizerAndFit(bannerPanelSizer);
    /** TEXT LABEL **/

    //body contains
    left_column_sizer = new wxBoxSizer (wxVERTICAL);
    middle_column_sizer = new wxBoxSizer (wxVERTICAL);
    right_column_sizer = new wxBoxSizer (wxVERTICAL);

    //left_column contains
    metronome = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    metronome->SetBackgroundColour (wxColor(153, 153, 153));

    /** TEXT LABEL **/
    auto metronomeLabel = new wxStaticText(metronome, wxID_ANY, "\n\n     Insert\nMetronome\n     Here");
    wxFont metronomeFont(40, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTSTYLE_NORMAL);
    metronomeLabel->SetFont(metronomeFont);
    metronomeLabel->SetBackgroundColour(wxColor(204, 204, 204));
    auto metronomePanelSizer = new wxBoxSizer(wxVERTICAL);
    metronomePanelSizer->Add(metronomeLabel, 1, wxALIGN_CENTER_HORIZONTAL | wxALL, FromDIP(45));
    metronome->SetSizerAndFit(metronomePanelSizer);
    /** TEXT LABEL **/

    output = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    output->SetBackgroundColour (wxColor(198,227,114));

    /** TEXT LABEL **/
    auto outputLabel = new wxStaticText(output, wxID_ANY, "Output to file:");
    wxFont outputFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTSTYLE_NORMAL);
    outputLabel->SetFont(outputFont);
    outputField = new wxTextCtrl(output, wxID_ANY, "", wxDefaultPosition,
                                 wxSize(FromDIP(20), wxDefaultSize.GetHeight()));
    outputField->SetBackgroundColour(wxColor(198,227,114));
    auto outputPanelSizer = new wxBoxSizer(wxVERTICAL);
    outputPanelSizer->Add(outputLabel, 0, wxEXPAND | wxALL);
    outputPanelSizer->Add(outputField, 0, wxEXPAND | wxALL, FromDIP(20));
    output->SetSizerAndFit(outputPanelSizer);
    /** TEXT LABEL **/

    generate = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    generate->SetBackgroundColour (wxColor(198, 227, 114));

    /** BUTTON **/
    wxButton* generateButton = new wxButton(generate, wxID_ANY, "GENERATE", wxDefaultPosition, wxDefaultSize);
    generateButton->SetBackgroundColour(wxColor(198,227,114));
    generateButton->SetForegroundColour(wxColor(198,227,114));
    auto generatePanelSizer = new wxBoxSizer(wxVERTICAL);
    generatePanelSizer->Add(generateButton, 1, wxALIGN_CENTER_HORIZONTAL);
    generate->SetSizerAndFit(generatePanelSizer);
    /** BUTTON **/

    //middle_column contains
    middle_top_sizer = new wxBoxSizer (wxHORIZONTAL);
    middle_second_sizer = new wxBoxSizer (wxHORIZONTAL);
    middle_left_sizer = new wxBoxSizer (wxVERTICAL);
    middle_right_sizer = new wxBoxSizer (wxVERTICAL);

    //middle_top contains
    startsWith = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    startsWith->SetBackgroundColour (wxColor(154, 207, 220));

    /** TEXT LABEL **/
    auto startsWithLabel = new wxStaticText(startsWith, wxID_ANY, "Starts With:");
    startsWithLabel->SetFont(startsWithFont);
    startsWithField = new wxTextCtrl(startsWith, wxID_ANY, "", wxDefaultPosition,
                                     wxSize(FromDIP(20), wxDefaultSize.GetHeight()));
    startsWithField->SetBackgroundColour(wxColor(154,207,220));
    auto startsWithPanelSizer = new wxBoxSizer(wxVERTICAL);
    startsWithPanelSizer->Add(startsWithLabel, 0, wxEXPAND | wxALL);
    startsWithPanelSizer->Add(startsWithField, 0, wxEXPAND | wxALL, FromDIP(20));
    startsWith->SetSizerAndFit(startsWithPanelSizer);
    /** TEXT LABEL **/

    endsWith = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    endsWith->SetBackgroundColour (wxColor(154,207,220));

    /** TEXT LABEL **/
    auto endsWithLabel = new wxStaticText(endsWith, wxID_ANY, "Ends with:");
    endsWithLabel->SetFont(startsWithFont);
    endsWithField = new wxTextCtrl(endsWith, wxID_ANY, "", wxDefaultPosition,
                                   wxSize(FromDIP(20), wxDefaultSize.GetHeight()));
    endsWithField->SetBackgroundColour(wxColor(154,207,220));
    auto endsWithPanelSizer = new wxBoxSizer(wxVERTICAL);
    endsWithPanelSizer->Add(endsWithLabel, 0, wxEXPAND | wxALL);
    endsWithPanelSizer->Add(endsWithField, 0, wxEXPAND | wxALL, FromDIP(20));
    endsWith->SetSizerAndFit(endsWithPanelSizer);
    /** TEXT LABEL **/

    contains = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    contains->SetBackgroundColour (wxColor(154,207,220));

    /** TEXT LABEL **/
    auto containsLabel = new wxStaticText(contains, wxID_ANY, "Contains:");
    containsLabel->SetFont(startsWithFont);
    containsField = new wxTextCtrl(contains, wxID_ANY, "", wxDefaultPosition,
                                   wxSize(FromDIP(20), wxDefaultSize.GetHeight()));
    containsField->SetBackgroundColour(wxColor(154,207,220));
    auto containsPanelSizer = new wxBoxSizer(wxVERTICAL);
    containsPanelSizer->Add(containsLabel, 0, wxEXPAND | wxALL);
    containsPanelSizer->Add(containsField, 0, wxEXPAND | wxALL, FromDIP(20));
    endsWith->SetSizerAndFit(containsPanelSizer);
    /** TEXT LABEL **/

    //middle_second contains
    letters = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    letters->SetBackgroundColour (wxColor(154,207,220));

    /** TEXT LABEL **/
    auto lettersLabel = new wxStaticText(letters, wxID_ANY, "Letters:");
    lettersLabel->SetFont(startsWithFont);
    lettersField = new wxTextCtrl(letters, wxID_ANY, "", wxDefaultPosition,
                                  wxSize(FromDIP(20), wxDefaultSize.GetHeight()));
    lettersField->SetBackgroundColour(wxColor(154,207,220));
    auto lettersPanelSizer = new wxBoxSizer(wxVERTICAL);
    lettersPanelSizer->Add(lettersLabel, 0, wxEXPAND | wxALL);
    lettersPanelSizer->Add(lettersField, 0, wxEXPAND | wxALL, FromDIP(20));
    letters->SetSizerAndFit(lettersPanelSizer);
    /** TEXT LABEL **/

    anagram = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    anagram->SetBackgroundColour (wxColor(154,207,220));

    //middle_left contains
    length = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    length->SetBackgroundColour (wxColor(154,207,220));

    /** TEXT LABEL **/
    auto lengthLabel = new wxStaticText(length, wxID_ANY, "Length:");
    lengthLabel->SetFont(startsWithFont);
    lengthField = new wxTextCtrl(length, wxID_ANY, "", wxDefaultPosition,
                                 wxSize(FromDIP(20), wxDefaultSize.GetHeight()));
    lengthField->SetBackgroundColour(wxColor(154,207,220));
    auto lengthPanelSizer = new wxBoxSizer(wxVERTICAL);
    lengthPanelSizer->Add(lengthLabel, 0, wxEXPAND | wxALL);
    lengthPanelSizer->Add(lengthField, 0, wxEXPAND | wxALL, FromDIP(20));
    length->SetSizerAndFit(lengthPanelSizer);
    /** TEXT LABEL **/

    syllables = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    syllables->SetBackgroundColour (wxColor(154,207,220));

    /** TEXT LABEL **/
    auto syllablesLabel = new wxStaticText(syllables, wxID_ANY, "Syllables:");
    syllablesLabel->SetFont(startsWithFont);
    syllablesField = new wxTextCtrl(syllables, wxID_ANY, "", wxDefaultPosition,
                                    wxSize(FromDIP(20), wxDefaultSize.GetHeight()));
    syllablesField->SetBackgroundColour(wxColor(154,207,220));
    auto syllablesPanelSizer = new wxBoxSizer(wxVERTICAL);
    syllablesPanelSizer->Add(syllablesLabel, 0, wxEXPAND | wxALL);
    syllablesPanelSizer->Add(syllablesField, 0, wxEXPAND | wxALL, FromDIP(20));
    syllables->SetSizerAndFit(syllablesPanelSizer);
    /** TEXT LABEL **/

    rhymesWith = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    rhymesWith->SetBackgroundColour (wxColor(154,207,220));

    /** TEXT LABEL **/
    auto rhymesWithLabel = new wxStaticText(rhymesWith, wxID_ANY, "Rhymes With:");
    rhymesWithLabel->SetFont(startsWithFont);
    rhymesWithField = new wxTextCtrl(rhymesWith, wxID_ANY, "", wxDefaultPosition,
                                     wxSize(FromDIP(20), wxDefaultSize.GetHeight()));
    rhymesWithField->SetBackgroundColour(wxColor(154,207,220));
    auto rhymesWithPanelSizer = new wxBoxSizer(wxVERTICAL);
    rhymesWithPanelSizer->Add(rhymesWithLabel, 0, wxEXPAND | wxALL);
    rhymesWithPanelSizer->Add(rhymesWithField, 0, wxEXPAND | wxALL, FromDIP(20));
    rhymesWith->SetSizerAndFit(rhymesWithPanelSizer);
    /** TEXT LABEL **/

    wordType = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    wordType->SetBackgroundColour (wxColor(154,207,220));

    //middle_right contains
    checkBoxes = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    checkBoxes->SetBackgroundColour (wxColor(154,207,220));
    middle_right_top_sizer = new wxBoxSizer (wxHORIZONTAL);
    middle_right_bottom_sizer = new wxBoxSizer (wxHORIZONTAL);

    //middle_right_top contains
    homophone = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    homophone->SetBackgroundColour (wxColor(154,207,220));

    /** TEXT LABEL **/
    auto homophoneLabel = new wxStaticText(homophone, wxID_ANY, "Homophone:");
    homophoneLabel->SetFont(startsWithFont);
    homophoneField = new wxTextCtrl(homophone, wxID_ANY, "", wxDefaultPosition,
                                    wxSize(FromDIP(20), wxDefaultSize.GetHeight()));
    homophoneField->SetBackgroundColour(wxColor(154,207,220));
    auto homophonePanelSizer = new wxBoxSizer(wxVERTICAL);
    homophonePanelSizer->Add(homophoneLabel, 0, wxEXPAND | wxALL);
    homophonePanelSizer->Add(homophoneField, 0, wxEXPAND | wxALL, FromDIP(20));
    homophone->SetSizerAndFit(homophonePanelSizer);
    /** TEXT LABEL **/

    omitLetters = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    omitLetters->SetBackgroundColour (wxColor(154,207,220));

    /** TEXT LABEL **/
    auto omitLettersLabel = new wxStaticText(omitLetters, wxID_ANY, "Omit Letters:");
    omitLettersLabel->SetFont(startsWithFont);
    omitLettersField = new wxTextCtrl(omitLetters, wxID_ANY, "", wxDefaultPosition,
                                      wxSize(FromDIP(20), wxDefaultSize.GetHeight()));
    omitLettersField->SetBackgroundColour(wxColor(154,207,220));
    auto omitLettersPanelSizer = new wxBoxSizer(wxVERTICAL);
    omitLettersPanelSizer->Add(omitLettersLabel, 0, wxEXPAND | wxALL);
    omitLettersPanelSizer->Add(omitLettersField, 0, wxEXPAND | wxALL, FromDIP(20));
    omitLetters->SetSizerAndFit(omitLettersPanelSizer);
    /** TEXT LABEL **/

    //middle_right_bottom contains
    synonym = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    synonym->SetBackgroundColour (wxColor(154,207,220));

    /** TEXT LABEL **/
    auto synonymLabel = new wxStaticText(synonym, wxID_ANY, "Synonym:");
    synonymLabel->SetFont(startsWithFont);
    synonymField = new wxTextCtrl(synonym, wxID_ANY, "", wxDefaultPosition,
                                  wxSize(FromDIP(20), wxDefaultSize.GetHeight()));
    synonymField->SetBackgroundColour(wxColor(154,207,220));
    auto synonymPanelSizer = new wxBoxSizer(wxVERTICAL);
    synonymPanelSizer->Add(synonymLabel, 0, wxEXPAND | wxALL);
    synonymPanelSizer->Add(synonymField, 0, wxEXPAND | wxALL, FromDIP(20));
    synonym->SetSizerAndFit(synonymPanelSizer);
    /** TEXT LABEL **/

    antonym = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    antonym->SetBackgroundColour (wxColor(154,207,220));

    /** TEXT LABEL **/
    auto antonymLabel = new wxStaticText(antonym, wxID_ANY, "Antonym:");
    antonymLabel->SetFont(startsWithFont);
    antonymField = new wxTextCtrl(antonym, wxID_ANY, "", wxDefaultPosition,
                                  wxSize(FromDIP(20), wxDefaultSize.GetHeight()));
    antonymField->SetBackgroundColour(wxColor(154,207,220));
    auto antonymPanelSizer = new wxBoxSizer(wxVERTICAL);
    antonymPanelSizer->Add(antonymLabel, 0, wxEXPAND | wxALL);
    antonymPanelSizer->Add(antonymField, 0, wxEXPAND | wxALL, FromDIP(20));
    antonym->SetSizerAndFit(antonymPanelSizer);
    /** TEXT LABEL **/

    //right_column contains
    wordList = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    wordList->SetBackgroundColour (wxColor(254, 227, 126));

}

void MyFrame::CombineSizers(){
    /** MIDDLE **/
    middle_right_bottom_sizer->Add(synonym, 1, wxEXPAND);
    middle_right_bottom_sizer->Add(antonym, 1, wxEXPAND);

    middle_right_top_sizer->Add(homophone, 1, wxEXPAND);
    middle_right_top_sizer->Add(omitLetters, 1, wxEXPAND);

    middle_right_sizer->Add(checkBoxes, 2, wxEXPAND);
    middle_right_sizer->Add(middle_right_top_sizer, 1, wxEXPAND);
    middle_right_sizer->Add(middle_right_bottom_sizer, 1, wxEXPAND);

    middle_left_sizer->Add(length, 1, wxEXPAND);
    middle_left_sizer->Add(syllables, 1, wxEXPAND);
    middle_left_sizer->Add(rhymesWith, 1, wxEXPAND);
    middle_left_sizer->Add(wordType, 1, wxEXPAND);

    middle_second_sizer->Add(letters, 2, wxEXPAND);
    middle_second_sizer->Add(anagram, 1, wxEXPAND);

    middle_top_sizer->Add(startsWith, 1, wxEXPAND);
    middle_top_sizer->Add(endsWith, 1, wxEXPAND);
    middle_top_sizer->Add(contains, 1, wxEXPAND);

    middle_bottom_chunk_sizer = new wxBoxSizer (wxHORIZONTAL);
    middle_bottom_chunk_sizer->Add(middle_left_sizer, 1, wxEXPAND);
    middle_bottom_chunk_sizer->Add(middle_right_sizer, 2, wxEXPAND);

    middle_column_sizer->Add(middle_top_sizer, 1, wxEXPAND);
    middle_column_sizer->Add(middle_second_sizer, 1, wxEXPAND);
    middle_column_sizer->Add(middle_bottom_chunk_sizer, 4, wxEXPAND);

    /** LEFT **/
    left_column_sizer->Add(metronome, 28, wxEXPAND);
    left_column_sizer->Add(output, 12, wxEXPAND);
    left_column_sizer->Add(generate, 12, wxEXPAND);

    /** RIGHT **/
    right_column_sizer->Add(wordList, 1, wxEXPAND);

    /** BODY **/
    body_sizer->Add(left_column_sizer, 25, wxEXPAND);
    body_sizer->Add(middle_column_sizer, 50, wxEXPAND);
    body_sizer->Add(right_column_sizer, 25, wxEXPAND);

    /** TOP BANNER **/
    top_banner_sizer->Add(banner, 1, wxEXPAND);

    /** MAIN SIZER **/
    main_sizer->Add(top_banner_sizer, 65, wxEXPAND);
    main_sizer->Add(body_sizer, 540, wxEXPAND);

    this->SetSizerAndFit (main_sizer);
}

void MyFrame::OnType(wxCommandEvent &e){
    std::cout << "[wxEVT_TEXT] Name Text: "<< e.GetString() << std::endl;
    wxTextCtrl *wordBar = wxDynamicCast(e.GetEventObject(), wxTextCtrl);
    wxPanel *p = wxDynamicCast(wordBar->GetParent(), wxPanel);
    if (e.GetString().length() > 0) {
        wordBar->SetBackgroundColour(wxColor(58, 175, 220));
        p->SetBackgroundColour(wxColor(58, 175, 220));
    } else {
        wordBar->SetBackgroundColour(wxColor(154, 207, 220));
        p->SetBackgroundColour(wxColor(154, 207, 220));
    }
    Refresh();
    e.Skip();
}

class MyPanel: public wxPanel
{
public:
    void setTextCtrlText(const wxString &str) { m_textCtrl->ChangeValue(str); };
private:
    wxTextCtrl *m_textCtrl;
};