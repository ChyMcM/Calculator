#pragma once
#include "wx/wx.h"
#include <iostream>
#include <string>
#include <format>
class Calculator : public wxFrame
{
public:
    Calculator(){}
    Calculator(const wxString& title, const wxPoint& pos, const wxSize& size);
    wxTextCtrl* display;
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
    std::string numstor;
    std::string displayfeed;
    std::vector<float> nums;
    std::vector<char> operas;
    int sum;
    int num1;
    bool add = false;
    bool diva = false;
    bool mult = false;
    bool sub = false;
    bool modu = false;
    bool hexa = false;
    bool binn = false;
    bool nega = false;
    bool deci = false;
    bool op1on = false;
    bool firstClick = true;
    int numo;
    int num2;
    float dec1;
    float dec2;
    float decsum;
    float decita = 1;
    std::string binnum;
    std::string hexnum;
    std::string numo1;
    std::string numo2;
    void OnButtonClick(wxCommandEvent& evt);
private:
    void OnExit(wxCommandEvent& event);
    wxDECLARE_EVENT_TABLE();
};