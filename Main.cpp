#include "Main.h"
#include "Calculator.h"
wxBEGIN_EVENT_TABLE(Calculator, wxFrame)
EVT_MENU(wxID_EXIT, Calculator::OnExit)
wxEND_EVENT_TABLE()
wxIMPLEMENT_APP(myApp);

bool myApp::OnInit()
{
    Calculator* frame = new Calculator("Calculator", wxPoint(50, 50), wxSize(265, 340));
    frame->Show(true);
    return true;
}