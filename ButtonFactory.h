#pragma once
#include "wx/wx.h"
class ButtonFactory
{
public:
	static wxButton* createButton(wxWindow* o, wxButton* d, int p, wxString v, wxPoint z, wxSize b);
};