#include "Calculator.h"
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
    but0 = new wxButton(this, 10000, "0", wxPoint(0, 50), wxSize(50, 50));
    but1 = new wxButton(this, 10001, "1", wxPoint(50, 50), wxSize(50, 50));
    but2 = new wxButton(this, 10002, "2", wxPoint(100, 50), wxSize(50, 50));
    but3 = new wxButton(this, 10003, "3", wxPoint(150, 50), wxSize(50, 50));
    clear = new wxButton(this, 10020, "Clear", wxPoint(200, 50), wxSize(50, 250));
    but4 = new wxButton(this, 10004, "4", wxPoint(0, 100), wxSize(50, 50));
    but5 = new wxButton(this, 10005, "5", wxPoint(50, 100), wxSize(50, 50));
    but6 = new wxButton(this, 10006, "6", wxPoint(100, 100), wxSize(50, 50));
    but7 = new wxButton(this, 10007, "7", wxPoint(150, 100), wxSize(50, 50));
    but8 = new wxButton(this, 10008, "8", wxPoint(0, 150), wxSize(50, 50));
    but9 = new wxButton(this, 10009, "9", wxPoint(50, 150), wxSize(50, 50));
    butequ = new wxButton(this, 10010, "=", wxPoint(150, 150), wxSize(50, 50));
    neg = new wxButton(this, 10011, "(-)", wxPoint(100, 150), wxSize(50, 50));
    butadd = new wxButton(this, 10012, "+", wxPoint(0, 200), wxSize(50, 50));
    butsub = new wxButton(this, 10013, "-", wxPoint(50, 200), wxSize(50, 50));
    butdiv = new wxButton(this, 10014, "/", wxPoint(100, 200), wxSize(50, 50));
    butmul = new wxButton(this, 10015, "*", wxPoint(150, 200), wxSize(50, 50));
    mod = new wxButton(this, 10016, "%", wxPoint(0, 250), wxSize(50, 50));
    dec = new wxButton(this, 10017, ".", wxPoint(50, 250), wxSize(50, 50));
    hex = new wxButton(this, 10018, "Hex", wxPoint(100, 250), wxSize(50, 50));
    bin = new wxButton(this, 10019, "Bin", wxPoint(150, 250), wxSize(50, 50));
}
void Calculator::OnExit(wxCommandEvent& event)
{
    Close(true);
}
