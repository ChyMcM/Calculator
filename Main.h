#pragma once
#include "wx/wx.h"
#include "Calculator.h"
class myApp : public wxApp
{
public:
    Calculator* frame;
    virtual bool OnInit();
};