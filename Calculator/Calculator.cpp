#include "Calculator.h"
#include "ButtonFactory.h"
Calculator::Calculator(const wxString& title, const wxPoint& pos, const wxSize& size) : wxFrame(NULL, wxID_ANY, title, pos, size)
{
	Center();
    wxMenu* menuFile = new wxMenu;
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenuBar* menuBar = new wxMenuBar;
    SetMenuBar(menuBar);
    wxFont font(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);
    wxTextCtrl* display = new wxTextCtrl(this, -1, wxT("0"), wxPoint(0, 0), wxSize(250, 50), wxTE_READONLY);
    int numofbuts = 0;
    ButtonFactory::createButton(this, but0, 10000 + numofbuts, "0", wxPoint(0, 50), wxSize(50, 50));
    ButtonFactory::createButton(this, but1, 10000 + numofbuts++, "1", wxPoint(50, 50), wxSize(50, 50));
    ButtonFactory::createButton(this, but2, 10000 + numofbuts++, "2", wxPoint(100, 50), wxSize(50, 50));
    ButtonFactory::createButton(this, but3, 10000 + numofbuts++, "3", wxPoint(150, 50), wxSize(50, 50));
    ButtonFactory::createButton(this, but4, 10000 + numofbuts++, "4", wxPoint(0, 100), wxSize(50, 50));
    ButtonFactory::createButton(this, but5, 10000 + numofbuts++, "5", wxPoint(50, 100), wxSize(50, 50));
    ButtonFactory::createButton(this, but6, 10000 + numofbuts++, "6", wxPoint(100, 100), wxSize(50, 50));
    ButtonFactory::createButton(this, but7, 10000 + numofbuts++, "7", wxPoint(150, 100), wxSize(50, 50));
    ButtonFactory::createButton(this, but8, 10000 + numofbuts++, "8", wxPoint(0, 150), wxSize(50, 50));
    ButtonFactory::createButton(this, but9, 10000 + numofbuts++, "9", wxPoint(50, 150), wxSize(50, 50));
    ButtonFactory::createButton(this, neg, 10000 + numofbuts++, "(-)", wxPoint(100, 150), wxSize(50, 50));
    ButtonFactory::createButton(this, butequ, 10000 + numofbuts++, "=", wxPoint(150, 150), wxSize(50, 50));
    ButtonFactory::createButton(this, butadd, 10000 + numofbuts++, "+", wxPoint(0, 200), wxSize(50, 50));
    ButtonFactory::createButton(this, butsub, 10000 + numofbuts++, "-", wxPoint(50, 200), wxSize(50, 50));
    ButtonFactory::createButton(this, butdiv, 10000 + numofbuts++, "/", wxPoint(100, 200), wxSize(50, 50));
    ButtonFactory::createButton(this, butmul, 10000 + numofbuts++, "*", wxPoint(150, 200), wxSize(50, 50));
    ButtonFactory::createButton(this, mod, 10000 + numofbuts++, "%", wxPoint(0, 250), wxSize(50, 50));
    ButtonFactory::createButton(this, dec, 10000 + numofbuts++, ".", wxPoint(50, 250), wxSize(50, 50));
    ButtonFactory::createButton(this, hex, 10000 + numofbuts++, "Hex", wxPoint(100, 250), wxSize(50, 50));
    ButtonFactory::createButton(this, bin, 10000 + numofbuts++, "Bin", wxPoint(150, 250), wxSize(50, 50));
    ButtonFactory::createButton(this, clear, 10000 + numofbuts++, "Clear", wxPoint(200, 50), wxSize(50, 250));
}
void Calculator::OnExit(wxCommandEvent& event)
{
    Close(true);
}
