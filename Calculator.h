#pragma once
#include "wx/wx.h"
class Calculator : public wxFrame
{
public:
    Calculator(const wxString& title, const wxPoint& pos, const wxSize& size);
    wxButton* but0;
    wxButton* but1;
    wxButton* but2;
    wxButton* but3;
    wxButton* but4;
    wxButton* but5;
    wxButton* but6;
    wxButton* but7;
    wxButton* but8;
    wxButton* but9;
    wxButton* butadd;
    wxButton* butmul;
    wxButton* butdiv;
    wxButton* butsub;
    wxButton* butequ;
    wxButton* clear;
    wxButton* mod;
    wxButton* dec;
    wxButton* hex;
    wxButton* bin;
    wxButton* neg;
private:
    void OnExit(wxCommandEvent& event);
    wxDECLARE_EVENT_TABLE();
};

