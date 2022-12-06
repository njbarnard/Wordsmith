// wxWidgets "Hello World" Program

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#include <iostream>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#include <wx/slider.h>
#endif

wxFont defaultFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTSTYLE_NORMAL);
wxFont defaultMediumFont(28, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTSTYLE_NORMAL);

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);

class MyFrame : public wxFrame{

public:
    MyFrame (const wxString &title, const wxPoint &pos, const wxSize &size);
    void OnTyping(wxCommandEvent &e);
    void OnOutputTyping(wxCommandEvent &e);
    void OnListBoxChecked(wxCommandEvent &e);
    void OnBoxChecked(wxCommandEvent &e);
    void OnSlide(wxCommandEvent &e);
    void OnChoice(wxCommandEvent &e);
    void OnButtonClicked(wxCommandEvent &e);
    void CreateGUI();
    void CombineSizers();
    void BindEvents();
    void InitializeBools();
    void SetValues(int ID, const std::string& text);
    void SetValues(int ID, bool val);
    void SetAnagram();
    void checkBoxesPanelChecker();

private:
    wxSizer *main_sizer, *top_banner_sizer, *body_sizer, *left_column_sizer, *middle_column_sizer,
    *right_column_sizer, *middle_first_sizer, *middle_second_sizer, *middle_third_sizer, *middle_third_left_sizer,
    *middle_fourth_sizer, *middle_fifth_sizer, *checkBoxesSizer, *generateWithBorder;

    wxPanel *banner, *metronome, *output, *generate, *startsWith, *endsWith, *contains, *letters, *anagram,
    *length, *syllables, *rhymesWith, *wordType, *homophone, *omitLetters, *synonym, *antonym, *checkBoxesPanel;

    wxListBox *wordList;

    wxCheckBox *anagramCheckBox;

    wxCheckListBox *checkBoxes;

    wxButton *generateButton;

    wxSlider *lengthSlider, *syllablesSlider;

    wxChoice *wordTypeChoice;

    int checkCount, lengthVal, syllablesVal;

    wxTextCtrl *startsWithField, *endsWithField, *containsField, *lettersField, *syllablesField,
    *rhymesWithField, *homophoneField, *omitLettersField, *synonymField, *antonymField, *outputField;

    std::string outputString, startsWithString, endsWithString, containsString, lettersString, anagramString,
    rhymesWithString, wordTypeString, homophoneString, omitLettersString, synonymString, antonymString;

    bool outputIsUsed, startsWithIsUsed, endsWithIsUsed, containsIsUsed, lettersIsUsed, anagramIsUsed, lengthIsUsed,
    syllablesIsUsed, rhymesWithIsUsed, wordTypeIsUsed, palindromeIsUsed, kangarooWordIsUsed, compoundWordIsUsed,
    properNounIsUsed, longListIsUsed, perfectRhymeIsUsed, homophoneIsUsed, omitLettersIsUsed, synonymIsUsed,
    antonymIsUsed;

};

enum ButtonId
{
    bannerID = wxID_LAST + 1, metronomeID, outputID, generateID, startsWithID, endsWithID, containsID,
    lettersID, anagramID, lengthID, syllablesID, rhymesWithID, wordTypeID, checkBoxesID, checkBoxesPanelID,
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
    InitializeBools();

}

void MyFrame::BindEvents(){
    generate->Bind(wxEVT_BUTTON, &MyFrame::OnButtonClicked, this);
    output->Bind(wxEVT_TEXT, &MyFrame::OnOutputTyping, this);
    startsWith->Bind(wxEVT_TEXT, &MyFrame::OnTyping, this);
    endsWith->Bind(wxEVT_TEXT, &MyFrame::OnTyping, this);
    contains->Bind(wxEVT_TEXT, &MyFrame::OnTyping, this);
    letters->Bind(wxEVT_TEXT, &MyFrame::OnTyping, this);
    rhymesWith->Bind(wxEVT_TEXT, &MyFrame::OnTyping, this);
    homophone->Bind(wxEVT_TEXT, &MyFrame::OnTyping, this);
    omitLetters->Bind(wxEVT_TEXT, &MyFrame::OnTyping, this);
    synonym->Bind(wxEVT_TEXT, &MyFrame::OnTyping, this);
    antonym->Bind(wxEVT_TEXT, &MyFrame::OnTyping, this);
    anagram->Bind(wxEVT_CHECKBOX, &MyFrame::OnBoxChecked, this);
    checkBoxes->Bind(wxEVT_CHECKLISTBOX, &MyFrame::OnListBoxChecked, this);
    length->Bind(wxEVT_SLIDER, &MyFrame::OnSlide, this);
    syllables->Bind(wxEVT_SLIDER, &MyFrame::OnSlide, this);
    wordType->Bind(wxEVT_CHOICE, &MyFrame::OnChoice, this);
}

void MyFrame::SetValues(int ID, const std::string& text){

    switch(ID){
        case outputID:
            if (text.length() > 0) {
                outputString = text;
                outputIsUsed = true;
            } else outputIsUsed = false;
            break;
        case startsWithID:
            if (text.length() > 0) {
                startsWithString = text;
                startsWithIsUsed = true;
            } else startsWithIsUsed = false;
            break;
        case endsWithID:
            if (text.length() > 0) {
                endsWithString = text;
                endsWithIsUsed = true;
            } else endsWithIsUsed = false;
            break;
        case containsID:
            if (text.length() > 0) {
                containsString = text;
                containsIsUsed = true;
            } else containsIsUsed = false;
            break;
        case lettersID:
            if (text.length() > 0) {
                lettersString = text;
                lettersIsUsed = true;
                if (!anagram->IsEnabled()) anagram->Enable();
            } else {lettersIsUsed = false; SetAnagram(); anagram->Disable();}
            break;
        case lengthID:
            break;
        case syllablesID:
            break;
        case rhymesWithID:
            if (text.length() > 0) {
                rhymesWithString = text;
                rhymesWithIsUsed = true;
            } else rhymesWithIsUsed = false;
            break;
        case wordTypeID:
            if (text.length() > 0) {
                wordTypeString = text;
                wordTypeIsUsed = true;
            } else wordTypeIsUsed = false;
            break;
        case homophoneID:
            if (text.length() > 0) {
                homophoneString = text;
                homophoneIsUsed = true;
                checkBoxesPanelChecker();
            } else {homophoneIsUsed = false; checkBoxesPanel->SetBackgroundColour(wxColor(154, 207, 220));}
            break;
        case omitLettersID:
            if (text.length() > 0) {
                omitLettersString = text;
                omitLettersIsUsed = true;
                checkBoxesPanelChecker();
            } else {omitLettersIsUsed = false; checkBoxesPanel->SetBackgroundColour(wxColor(154, 207, 220));}
            break;
        case synonymID:
            if (text.length() > 0) {
                synonymString = text;
                synonymIsUsed = true;
            } else synonymIsUsed = false;
            break;
        case antonymID:
            if (text.length() > 0) {
                antonymString = text;
                antonymIsUsed = true;
            } else antonymIsUsed = false;
            break;
        default:
            std::cout << "Error in SetValues() !" << std::endl;
            break;
    }
}

void MyFrame::SetValues(int ID, bool val){

    switch(ID){
        case anagramID:
            if (val) anagramIsUsed = true;
            else anagramIsUsed = false;
            break;
        default:
            std::cout << "Error in SetValues() !" << std::endl;
            break;
    }
}

void MyFrame::SetAnagram(){
    anagram->SetBackgroundColour(wxColor(154, 207, 220));
    anagramCheckBox->SetBackgroundColour(wxColor(154, 207, 220));
    anagramCheckBox->SetValue(false);
    anagramIsUsed = false;
}

void MyFrame::checkBoxesPanelChecker(){
    if (syllablesIsUsed && homophoneIsUsed && omitLettersIsUsed && (checkCount > 0)){
        checkBoxesPanel->SetBackgroundColour(wxColor(58, 175, 220));
    }
}

void MyFrame::OnTyping(wxCommandEvent &e){

    wxTextCtrl *wordBar = wxDynamicCast(e.GetEventObject(), wxTextCtrl);
    wxPanel *panel = wxDynamicCast(wordBar->GetParent(), wxPanel);

    if (e.GetString().length() > 0) {
        wordBar->SetBackgroundColour(wxColor(58, 175, 220));
        panel->SetBackgroundColour(wxColor(58, 175, 220));
    } else {
        wordBar->SetBackgroundColour(wxColor(154, 207, 220));
        panel->SetBackgroundColour(wxColor(154, 207, 220));
    }

    SetValues(panel->GetId(), e.GetString().ToStdString());

    Refresh();
    e.Skip();
}

void MyFrame::OnOutputTyping(wxCommandEvent &e){

    wxTextCtrl *wordBar = wxDynamicCast(e.GetEventObject(), wxTextCtrl);
    wxPanel *panel = wxDynamicCast(wordBar->GetParent(), wxPanel);

    if (e.GetString().length() > 0) {
        wordBar->SetBackgroundColour(wxColor(160, 203, 30));
        panel->SetBackgroundColour(wxColor(160, 203, 30));
    } else {
        wordBar->SetBackgroundColour(wxColor(198,227,114));
        panel->SetBackgroundColour(wxColor(198,227,114));
    }

    SetValues(panel->GetId(), e.GetString().ToStdString());

    Refresh();
    e.Skip();
}

void MyFrame::OnBoxChecked(wxCommandEvent &e){
    wxCheckBox *checkBox = wxDynamicCast(e.GetEventObject(), wxCheckBox);
    wxPanel *panel = wxDynamicCast(checkBox->GetParent(), wxPanel);

    if (e.IsChecked()) {
        checkBox->SetBackgroundColour(wxColor(58, 175, 220));
        panel->SetBackgroundColour(wxColor(58, 175, 220));
    } else {
        checkBox->SetBackgroundColour(wxColor(154, 207, 220));
        panel->SetBackgroundColour(wxColor(154, 207, 220));
    }

    SetValues(panel->GetId(), e.IsChecked());

    Refresh();
    e.Skip();
}

void MyFrame::OnListBoxChecked(wxCommandEvent &e){

    bool isChecked = false;

    switch(e.GetSelection()){
        case 0:
            palindromeIsUsed = !palindromeIsUsed;
            isChecked = palindromeIsUsed;
            break;
        case 1:
            kangarooWordIsUsed = !kangarooWordIsUsed;
            isChecked = kangarooWordIsUsed;
            break;
        case 2:
            compoundWordIsUsed = !compoundWordIsUsed;
            isChecked = compoundWordIsUsed;
            break;
        case 3:
            properNounIsUsed = !properNounIsUsed;
            isChecked = properNounIsUsed;
            break;
        case 4:
            longListIsUsed = !longListIsUsed;
            isChecked = longListIsUsed;
            break;
        case 5:
            perfectRhymeIsUsed = !perfectRhymeIsUsed;
            isChecked = perfectRhymeIsUsed;
            break;
        default:
            std::cout << "Error in OnListBoxChecked !" << std::endl;
            break;
    }

    if (isChecked) checkCount++;
    else checkCount--;

    if (checkCount > 0) {
        checkBoxes->SetBackgroundColour(wxColor(58, 175, 220));
        checkBoxesPanelChecker();
    } else {
        checkBoxes->SetBackgroundColour(wxColor(154, 207, 220));
        checkBoxesPanel->SetBackgroundColour(wxColor(154, 207, 220));
    }

    Refresh();
    e.Skip();
}

void MyFrame::OnSlide(wxCommandEvent &e){
    wxSlider *slider = wxDynamicCast(e.GetEventObject(), wxSlider);
    wxPanel *panel = wxDynamicCast(slider->GetParent(), wxPanel);

    if (panel->GetId() == lengthID){

        lengthVal = lengthSlider->GetValue();
        if (lengthVal > 0){
            lengthIsUsed = true; length->SetBackgroundColour(wxColor(58, 175, 220));
        }
        else {lengthIsUsed = false; length->SetBackgroundColour(wxColor(154, 207, 220));}

    } else if (panel->GetId() == syllablesID){

        syllablesVal = syllablesSlider->GetValue();
        if (syllablesVal > 0){
            syllablesIsUsed = true;
            syllables->SetBackgroundColour(wxColor(58, 175, 220));
            checkBoxesPanelChecker();
        }
        else {
            syllablesIsUsed = false;
            syllables->SetBackgroundColour(wxColor(154, 207, 220));
            checkBoxesPanel->SetBackgroundColour(wxColor(154, 207, 220));
        }

    } else std::cout << "Error in OnSlide !" << std::endl;

    Refresh();
    e.Skip();
}

void MyFrame::OnChoice(wxCommandEvent &e){
    wxChoice *choice = wxDynamicCast(e.GetEventObject(), wxChoice);
    wxPanel *panel = wxDynamicCast(choice->GetParent(), wxPanel);

    if (choice->GetSelection() == 0){
        panel->SetBackgroundColour(wxColor(154, 207, 220));
        wordTypeIsUsed = false;
    } else {
        panel->SetBackgroundColour(wxColor(58, 175, 220));
        wordTypeIsUsed = true;
        switch (choice->GetSelection()) {
            case 1:
                wordTypeString = "Noun";
                break;
            case 2:
                wordTypeString = "Verb";
                break;
            case 3:
                wordTypeString = "Adjective";
                break;
            case 4:
                wordTypeString = "Adverb";
                break;
            case 5:
                wordTypeString = "Pronoun";
                break;
            case 6:
                wordTypeString = "Preposition";
                break;
            case 7:
                wordTypeString = "Conjunction";
                break;
            default:
                std::cout << "Error in onChoice !" << std::endl;
                break;
        }
    }

    Refresh();
    e.Skip();
}

void MyFrame::OnButtonClicked(wxCommandEvent &e){
    wordList->AppendString(startsWithString);
    e.Skip();
}

void MyFrame::CreateGUI() {
    main_sizer = new wxBoxSizer (wxVERTICAL);

    /** MAIN CONTAINS **/
    top_banner_sizer = new wxBoxSizer (wxHORIZONTAL);
    body_sizer = new wxBoxSizer (wxHORIZONTAL);

    /** TOP_BANNER CONTAINS **/
    banner = new wxPanel(this, bannerID, wxDefaultPosition, wxDefaultSize);
    banner->SetBackgroundColour (wxColor(239, 90, 103));

    //--BANNER TEXT FIELD--//
    auto bannerLabel = new wxStaticText(banner, wxID_ANY, "Wordsmith");
    wxFont bannerFont(100, wxFONTFAMILY_DECORATIVE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    bannerLabel->SetFont(bannerFont);
    auto bannerPanelSizer = new wxBoxSizer(wxVERTICAL);
    bannerPanelSizer->Add(bannerLabel, 1, wxALIGN_CENTER_HORIZONTAL);
    banner->SetSizerAndFit(bannerPanelSizer);
    //--BANNER TEXT FIELD--//

    /** BODY CONTAINS **/
    left_column_sizer = new wxBoxSizer (wxVERTICAL);
    middle_column_sizer = new wxBoxSizer (wxVERTICAL);
    right_column_sizer = new wxBoxSizer (wxVERTICAL);

    /** LEFT_COLUMN CONTAINS **/
    metronome = new wxPanel(this, metronomeID, wxDefaultPosition, wxDefaultSize);
    metronome->SetBackgroundColour (wxColor(153, 153, 153));

    //--METRONOME TEXT LABEL--//
    auto metronomeLabel = new wxStaticText(metronome, wxID_ANY, "\n\n     Insert\nMetronome\n     Here");
    wxFont metronomeFont(40, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTSTYLE_NORMAL);
    metronomeLabel->SetFont(metronomeFont);
    metronomeLabel->SetBackgroundColour(wxColor(204, 204, 204));
    auto metronomePanelSizer = new wxBoxSizer(wxVERTICAL);
    metronomePanelSizer->Add(metronomeLabel, 1, wxALIGN_CENTER_HORIZONTAL | wxALL, FromDIP(45));
    metronome->SetSizerAndFit(metronomePanelSizer);
    //--METRONOME TEXT LABEL--//

    output = new wxPanel(this, outputID, wxDefaultPosition, wxDefaultSize);
    output->SetBackgroundColour (wxColor(198,227,114));

    //--OUTPUT TEXT FIELD--//
    auto outputLabel = new wxStaticText(output, wxID_ANY, " Output to file:");
    wxFont outputFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTSTYLE_NORMAL);
    outputLabel->SetFont(outputFont);
    outputField = new wxTextCtrl(output, wxID_ANY, "", wxDefaultPosition,
                                 wxSize(FromDIP(20), wxDefaultSize.GetHeight()));
    outputField->SetBackgroundColour(wxColor(198,227,114));
    auto outputPanelSizer = new wxBoxSizer(wxVERTICAL);
    outputPanelSizer->Add(outputLabel, 0, wxEXPAND | wxALL);
    outputPanelSizer->Add(outputField, 0, wxEXPAND | wxALL, FromDIP(20));
    output->SetSizerAndFit(outputPanelSizer);
    //--OUTPUT TEXT FIELD--//

    generate = new wxPanel(this, generateID, wxDefaultPosition, wxDefaultSize);
    generate->SetBackgroundColour (wxColor(198, 227, 114));

    //--GENERATE BUTTON--//
    generateButton = new wxButton(generate, wxID_ANY, "GENERATE", wxDefaultPosition, wxDefaultSize, wxBORDER_NONE);
    auto generatePanelSizer = new wxBoxSizer(wxVERTICAL);
    generateButton->SetBackgroundColour(wxColor(0,172,2));
    generatePanelSizer->Add(generateButton, 1, wxEXPAND, FromDIP(400));
    generate->SetSizerAndFit(generatePanelSizer);

    auto border_top = new wxPanel(this, generateID, wxDefaultPosition, wxDefaultSize);
    border_top->SetBackgroundColour (wxColor(198, 227, 114));
    auto border_bottom = new wxPanel(this, generateID, wxDefaultPosition, wxDefaultSize);
    border_bottom->SetBackgroundColour (wxColor(198, 227, 114));
    auto border_left = new wxPanel(this, generateID, wxDefaultPosition, wxDefaultSize);
    border_left->SetBackgroundColour (wxColor(198, 227, 114));
    auto border_right = new wxPanel(this, generateID, wxDefaultPosition, wxDefaultSize);
    border_right->SetBackgroundColour (wxColor(198, 227, 114));

    auto generateVertical = new wxBoxSizer(wxVERTICAL);
    generateVertical->Add(border_top, 1, wxEXPAND);
    generateVertical->Add(generate, 3, wxEXPAND);
    generateVertical->Add(border_bottom, 1, wxEXPAND);

    generateWithBorder = new wxBoxSizer(wxHORIZONTAL);
    generateWithBorder->Add(border_left, 1, wxEXPAND);
    generateWithBorder->Add(generateVertical, 3, wxEXPAND);
    generateWithBorder->Add(border_right, 1, wxEXPAND);
    //--GENERATE BUTTON--//

    /** MIDDLE_COLUMN CONTAINS **/
    middle_first_sizer = new wxBoxSizer (wxHORIZONTAL);
    middle_second_sizer = new wxBoxSizer (wxHORIZONTAL);
    middle_third_sizer = new wxBoxSizer (wxHORIZONTAL);
    middle_fourth_sizer = new wxBoxSizer (wxHORIZONTAL);
    middle_fifth_sizer = new wxBoxSizer (wxHORIZONTAL);

    /** MIDDLE_FIRST CONTAINS **/
    startsWith = new wxPanel(this, startsWithID, wxDefaultPosition, wxDefaultSize);
    startsWith->SetBackgroundColour (wxColor(154, 207, 220));

    //--STARTS WITH TEXT FIELD--//
    auto startsWithLabel = new wxStaticText(startsWith, wxID_ANY, " Starts with:");
    startsWithLabel->SetFont(defaultFont);
    startsWithField = new wxTextCtrl(startsWith, wxID_ANY, "", wxDefaultPosition,
                                     wxSize(FromDIP(20), wxDefaultSize.GetHeight()));
    startsWithField->SetBackgroundColour(wxColor(154,207,220));
    auto startsWithPanelSizer = new wxBoxSizer(wxVERTICAL);
    startsWithPanelSizer->Add(startsWithLabel, 0, wxEXPAND | wxALL);
    startsWithPanelSizer->Add(startsWithField, 0, wxEXPAND | wxALL, FromDIP(20));
    startsWith->SetSizerAndFit(startsWithPanelSizer);
    //--STARTS WITH TEXT FIELD--//

    endsWith = new wxPanel(this, endsWithID, wxDefaultPosition, wxDefaultSize);
    endsWith->SetBackgroundColour (wxColor(154,207,220));

    //--ENDS WITH TEXT FIELD--//
    auto endsWithLabel = new wxStaticText(endsWith, wxID_ANY, " Ends with:     ");
    endsWithLabel->SetFont(defaultFont);
    endsWithField = new wxTextCtrl(endsWith, wxID_ANY, "", wxDefaultPosition,
                                   wxSize(FromDIP(20), wxDefaultSize.GetHeight()));
    endsWithField->SetBackgroundColour(wxColor(154,207,220));
    auto endsWithPanelSizer = new wxBoxSizer(wxVERTICAL);
    endsWithPanelSizer->Add(endsWithLabel, 0, wxEXPAND | wxALL);
    endsWithPanelSizer->Add(endsWithField, 0, wxEXPAND | wxALL, FromDIP(20));
    endsWith->SetSizerAndFit(endsWithPanelSizer);
    //--ENDS WITH TEXT FIELD--//

    contains = new wxPanel(this, containsID, wxDefaultPosition, wxDefaultSize);
    contains->SetBackgroundColour (wxColor(154,207,220));

    //--CONTAINS TEXT FIELD--//
    auto containsLabel = new wxStaticText(contains, wxID_ANY, " Contains:");
    containsLabel->SetFont(defaultFont);
    containsField = new wxTextCtrl(contains, wxID_ANY, "", wxDefaultPosition,
                                   wxSize(FromDIP(20), wxDefaultSize.GetHeight()));
    containsField->SetBackgroundColour(wxColor(154,207,220));
    auto containsPanelSizer = new wxBoxSizer(wxVERTICAL);
    containsPanelSizer->Add(containsLabel, 0, wxEXPAND | wxALL);
    containsPanelSizer->Add(containsField, 0, wxEXPAND | wxALL, FromDIP(20));
    endsWith->SetSizerAndFit(containsPanelSizer);
    //--CONTAINS TEXT FIELD--//

    /** MIDDLE_SECOND CONTAINS **/
    letters = new wxPanel(this, lettersID, wxDefaultPosition, wxDefaultSize);
    letters->SetBackgroundColour (wxColor(154,207,220));

    //--LETTERS TEXT FIELD--//
    auto lettersLabel = new wxStaticText(letters, wxID_ANY, " Letters:");
    lettersLabel->SetFont(defaultFont);
    lettersField = new wxTextCtrl(letters, wxID_ANY, "", wxDefaultPosition,
                                  wxSize(FromDIP(20), wxDefaultSize.GetHeight()));
    lettersField->SetBackgroundColour(wxColor(154,207,220));
    auto lettersPanelSizer = new wxBoxSizer(wxVERTICAL);
    lettersPanelSizer->Add(lettersLabel, 0, wxEXPAND | wxALL);
    lettersPanelSizer->Add(lettersField, 0, wxEXPAND | wxALL, FromDIP(20));
    letters->SetSizerAndFit(lettersPanelSizer);
    //--LETTERS TEXT FIELD--//

    anagram = new wxPanel(this, anagramID, wxDefaultPosition, wxDefaultSize);
    anagram->SetBackgroundColour (wxColor(154,207,220));

    //--ANAGRAM CHECK BOX--//
    anagramCheckBox = new wxCheckBox(anagram, wxID_ANY, "Anagram", wxDefaultPosition,
                                  wxSize(FromDIP(20), wxDefaultSize.GetHeight()));
    anagramCheckBox->SetBackgroundColour(wxColor(154,207,220));
    anagramCheckBox->SetFont(wxFont(25, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTSTYLE_NORMAL));
    auto anagramPanelSizer = new wxBoxSizer(wxVERTICAL);
    anagramPanelSizer->Add(anagramCheckBox, 0, wxEXPAND | wxALL, FromDIP(20));
    anagram->SetSizerAndFit(anagramPanelSizer);
    anagram->Disable();
    //--ANAGRAM CHECK BOX--//

    /** MIDDLE_THIRD CONTAINS **/
    middle_third_left_sizer = new wxBoxSizer (wxVERTICAL);
    checkBoxesPanel = new wxPanel(this, checkBoxesPanelID, wxDefaultPosition, wxDefaultSize);
    checkBoxesPanel->SetBackgroundColour (wxColor(154,207,220));

    //--CHECKBOXES--//
    checkBoxes = new wxCheckListBox(this, checkBoxesID, wxDefaultPosition,
                                    wxSize(FromDIP(5), wxDefaultSize.GetHeight()));
    checkBoxes->Append("Palindrome");
    checkBoxes->Append("Kangaroo Word");
    checkBoxes->Append("Compound Word");
    checkBoxes->Append("Proper Noun");
    checkBoxes->Append("Long Word List");
    checkBoxes->Append("Perfect Rhyme");
    checkBoxes->SetBackgroundColour(wxColor(154,207,220));
    checkBoxes->SetFont(wxFont(26, wxFONTFAMILY_DEFAULT,
                               wxFONTSTYLE_NORMAL, wxFONTSTYLE_NORMAL));
    checkBoxesSizer = new wxBoxSizer (wxVERTICAL);
    checkBoxesSizer->Add(checkBoxes, 100, wxEXPAND);
    checkBoxesSizer->Add(checkBoxesPanel, 26, wxEXPAND);
    //--CHECKBOXES--//

    /** MIDDLE_THIRD_LEFT CONTAINS **/
    length = new wxPanel(this, lengthID, wxDefaultPosition, wxDefaultSize);
    length->SetBackgroundColour (wxColor(154,207,220));

    //--LENGTH SLIDER--//
    auto lengthLabel = new wxStaticText(length, wxID_ANY, " Length:");
    lengthLabel->SetFont(defaultFont);
    lengthSlider = new wxSlider(length, wxID_ANY, 1, 0, 30, wxDefaultPosition,
                                wxDefaultSize, m_windowStyle=wxSL_LABELS);
    lengthSlider->SetFont(wxFont(14, wxMODERN, wxFONTSTYLE_NORMAL,
                                 wxFONTSTYLE_NORMAL));
    lengthSlider->SetValue(0);
    auto lengthPanelSizer = new wxBoxSizer(wxVERTICAL);
    lengthPanelSizer->Add(lengthLabel, 0, wxEXPAND | wxALL);
    lengthPanelSizer->Add(lengthSlider, 0, wxEXPAND | wxALL, FromDIP(25));
    length->SetSizerAndFit(lengthPanelSizer);
    //--LENGTH SLIDER--//

    syllables = new wxPanel(this, syllablesID, wxDefaultPosition, wxDefaultSize);
    syllables->SetBackgroundColour (wxColor(154,207,220));

    //--SYLLABLES SLIDER--//
    auto syllablesLabel = new wxStaticText(syllables, wxID_ANY, " Syllables:");
    syllablesLabel->SetFont(defaultFont);
    syllablesSlider = new wxSlider(syllables, wxID_ANY, 1, 0, 10, wxDefaultPosition,
                                wxDefaultSize, m_windowStyle=wxSL_LABELS);
    syllablesSlider->SetFont(wxFont(14, wxMODERN, wxFONTSTYLE_NORMAL,
                                 wxFONTSTYLE_NORMAL));
    syllablesSlider->SetValue(0);
    auto syllablesPanelSizer = new wxBoxSizer(wxVERTICAL);
    syllablesPanelSizer->Add(syllablesLabel, 0, wxEXPAND | wxALL);
    syllablesPanelSizer->Add(syllablesSlider, 0, wxEXPAND | wxALL, FromDIP(25));
    syllables->SetSizerAndFit(syllablesPanelSizer);
    //--SYLLABLES SLIDER--//

    /** MIDDLE_FOURTH CONTAINS **/
    rhymesWith = new wxPanel(this, rhymesWithID, wxDefaultPosition, wxDefaultSize);
    rhymesWith->SetBackgroundColour (wxColor(154,207,220));

    //--RHYMES WITH TEXT FIELD--//
    auto rhymesWithLabel = new wxStaticText(rhymesWith, wxID_ANY, " Rhymes with:");
    rhymesWithLabel->SetFont(defaultMediumFont);
    rhymesWithField = new wxTextCtrl(rhymesWith, wxID_ANY, "", wxDefaultPosition,
                                     wxSize(FromDIP(20), wxDefaultSize.GetHeight()));
    rhymesWithField->SetBackgroundColour(wxColor(154,207,220));
    auto rhymesWithPanelSizer = new wxBoxSizer(wxVERTICAL);
    rhymesWithPanelSizer->Add(rhymesWithLabel, 0, wxEXPAND | wxALL);
    rhymesWithPanelSizer->Add(rhymesWithField, 0, wxEXPAND | wxALL, FromDIP(20));
    rhymesWith->SetSizerAndFit(rhymesWithPanelSizer);
    //--RHYMES WITH TEXT FIELD--//

    homophone = new wxPanel(this, homophoneID, wxDefaultPosition, wxDefaultSize);
    homophone->SetBackgroundColour (wxColor(154,207,220));

    //--HOMOPHONE TEXT FIELD--//
    auto homophoneLabel = new wxStaticText(homophone, wxID_ANY, " Homophone:");
    homophoneLabel->SetFont(defaultMediumFont);
    homophoneField = new wxTextCtrl(homophone, wxID_ANY, "", wxDefaultPosition,
                                    wxSize(FromDIP(20), wxDefaultSize.GetHeight()));
    homophoneField->SetBackgroundColour(wxColor(154,207,220));
    auto homophonePanelSizer = new wxBoxSizer(wxVERTICAL);
    homophonePanelSizer->Add(homophoneLabel, 0, wxEXPAND | wxALL);
    homophonePanelSizer->Add(homophoneField, 0, wxEXPAND | wxALL, FromDIP(20));
    homophone->SetSizerAndFit(homophonePanelSizer);
    //--HOMOPHONE TEXT FIELD--//

    omitLetters = new wxPanel(this, omitLettersID, wxDefaultPosition, wxDefaultSize);
    omitLetters->SetBackgroundColour (wxColor(154,207,220));

    //--OMIT LETTERS TEXT FIELD--//
    auto omitLettersLabel = new wxStaticText(omitLetters, wxID_ANY, " Omit Letters:");
    omitLettersLabel->SetFont(defaultMediumFont);
    omitLettersField = new wxTextCtrl(omitLetters, wxID_ANY, "", wxDefaultPosition,
                                      wxSize(FromDIP(20), wxDefaultSize.GetHeight()));
    omitLettersField->SetBackgroundColour(wxColor(154,207,220));
    auto omitLettersPanelSizer = new wxBoxSizer(wxVERTICAL);
    omitLettersPanelSizer->Add(omitLettersLabel, 0, wxEXPAND | wxALL);
    omitLettersPanelSizer->Add(omitLettersField, 0, wxEXPAND | wxALL, FromDIP(20));
    omitLetters->SetSizerAndFit(omitLettersPanelSizer);
    //--OMIT LETTERS TEXT FIELD--//

    /** MIDDLE_FIFTH CONTAINS **/
    wordType = new wxPanel(this, wordTypeID, wxDefaultPosition, wxDefaultSize);
    wordType->SetBackgroundColour (wxColor(154,207,220));

    //--WORD TYPE CHOICE--//
    auto wordTypeLabel = new wxStaticText(wordType, wxID_ANY, " Word Type:");
    wordTypeLabel->SetFont(defaultMediumFont);
    wordTypeChoice = new wxChoice(wordType, wxID_ANY, wxDefaultPosition, wxDefaultSize);
    wordTypeChoice->Append("");
    wordTypeChoice->Append("Noun");
    wordTypeChoice->Append("Verb");
    wordTypeChoice->Append("Adjective");
    wordTypeChoice->Append("Adverb");
    wordTypeChoice->Append("Pronoun");
    wordTypeChoice->Append("Preposition");
    wordTypeChoice->Append("Conjunction");
    wordTypeChoice->SetBackgroundColour(wxColor(154,207,220));
    auto wordTypePanelSizer = new wxBoxSizer(wxVERTICAL);
    wordTypePanelSizer->Add(wordTypeLabel, 0, wxEXPAND | wxALL);
    wordTypePanelSizer->Add(wordTypeChoice, 0, wxEXPAND | wxALL, FromDIP(25));
    wordType->SetSizerAndFit(wordTypePanelSizer);
    //--WORD TYPE CHOICE--//

    synonym = new wxPanel(this, synonymID, wxDefaultPosition, wxDefaultSize);
    synonym->SetBackgroundColour (wxColor(154,207,220));

    //--SYNONYM TEXT FIELD--//
    auto synonymLabel = new wxStaticText(synonym, wxID_ANY, " Synonym:");
    synonymLabel->SetFont(defaultMediumFont);
    synonymField = new wxTextCtrl(synonym, wxID_ANY, "", wxDefaultPosition,
                                  wxSize(FromDIP(20), wxDefaultSize.GetHeight()));
    synonymField->SetBackgroundColour(wxColor(154,207,220));
    auto synonymPanelSizer = new wxBoxSizer(wxVERTICAL);
    synonymPanelSizer->Add(synonymLabel, 0, wxEXPAND | wxALL);
    synonymPanelSizer->Add(synonymField, 0, wxEXPAND | wxALL, FromDIP(20));
    synonym->SetSizerAndFit(synonymPanelSizer);
    //--SYNONYM TEXT FIELD--//

    antonym = new wxPanel(this, antonymID, wxDefaultPosition, wxDefaultSize);
    antonym->SetBackgroundColour (wxColor(154,207,220));

    //--ANTONYM TEXT FIELD--//
    auto antonymLabel = new wxStaticText(antonym, wxID_ANY, " Antonym:");
    antonymLabel->SetFont(defaultMediumFont);
    antonymField = new wxTextCtrl(antonym, wxID_ANY, "", wxDefaultPosition,
                                  wxSize(FromDIP(20), wxDefaultSize.GetHeight()));
    antonymField->SetBackgroundColour(wxColor(154,207,220));
    auto antonymPanelSizer = new wxBoxSizer(wxVERTICAL);
    antonymPanelSizer->Add(antonymLabel, 0, wxEXPAND | wxALL);
    antonymPanelSizer->Add(antonymField, 0, wxEXPAND | wxALL, FromDIP(20));
    antonym->SetSizerAndFit(antonymPanelSizer);
    //--ANTONYM TEXT FIELD--//

    /** RIGHT_COLUMN CONTAINS **/
    wordList = new wxListBox(this, wordListID,wxDefaultPosition, wxDefaultSize);
    wordList->SetBackgroundColour (wxColor(254, 227, 126));

}

void MyFrame::CombineSizers(){

    /** MIDDLE **/
    middle_first_sizer->Add(startsWith, 1, wxEXPAND);
    middle_first_sizer->Add(endsWith, 1, wxEXPAND);
    middle_first_sizer->Add(contains, 1, wxEXPAND);

    middle_second_sizer->Add(letters, 2, wxEXPAND);
    middle_second_sizer->Add(anagram, 1, wxEXPAND);

    middle_third_left_sizer->Add(length, 1, wxEXPAND);
    middle_third_left_sizer->Add(syllables, 1, wxEXPAND);

    middle_third_sizer->Add(middle_third_left_sizer, 20, wxEXPAND);
    middle_third_sizer->Add(checkBoxesSizer, 15, wxEXPAND);

    middle_fourth_sizer->Add(rhymesWith, 1, wxEXPAND);
    middle_fourth_sizer->Add(homophone, 1, wxEXPAND);
    middle_fourth_sizer->Add(omitLetters, 1, wxEXPAND);

    middle_fifth_sizer->Add(wordType, 1, wxEXPAND);
    middle_fifth_sizer->Add(synonym, 1, wxEXPAND);
    middle_fifth_sizer->Add(antonym, 1, wxEXPAND);

    middle_column_sizer->Add(middle_first_sizer, 1, wxEXPAND);
    middle_column_sizer->Add(middle_second_sizer, 1, wxEXPAND);
    middle_column_sizer->Add(middle_third_sizer, 2, wxEXPAND);
    middle_column_sizer->Add(middle_fourth_sizer, 1, wxEXPAND);
    middle_column_sizer->Add(middle_fifth_sizer, 1, wxEXPAND);

    /** LEFT **/
    left_column_sizer->Add(metronome, 28, wxEXPAND);
    left_column_sizer->Add(output, 12, wxEXPAND);
    left_column_sizer->Add(generateWithBorder, 12, wxEXPAND);

    /** RIGHT **/
    right_column_sizer->Add(wordList, 1, wxEXPAND);

    /** BODY **/
    body_sizer->Add(left_column_sizer, 25, wxEXPAND);
    body_sizer->Add(middle_column_sizer, 50, wxEXPAND);
    body_sizer->Add(right_column_sizer, 25, wxEXPAND);

    /** TOP BANNER **/
    top_banner_sizer->Add(banner, 1, wxEXPAND);

    /** MAIN **/
    main_sizer->Add(top_banner_sizer, 65, wxEXPAND);
    main_sizer->Add(body_sizer, 540, wxEXPAND);

    this->SetSizerAndFit (main_sizer);
}

void MyFrame::InitializeBools(){
    //SET ALL BOOLS TO FALSE
    outputIsUsed = startsWithIsUsed = endsWithIsUsed = containsIsUsed = lettersIsUsed = anagramIsUsed = lengthIsUsed =
    syllablesIsUsed = rhymesWithIsUsed = wordTypeIsUsed = palindromeIsUsed = kangarooWordIsUsed = compoundWordIsUsed =
    properNounIsUsed = homophoneIsUsed = omitLettersIsUsed = synonymIsUsed = antonymIsUsed = false;

    //CHANGE CHECKCOUNT TO 0
    checkCount = 0;
}