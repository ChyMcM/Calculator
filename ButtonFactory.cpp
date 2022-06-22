#include "ButtonFactory.h"
#include "Calculator.h"
#include "Main.h"
wxButton* ButtonFactory::createButton(wxWindow* o, wxButton* d, int p, wxString v, wxPoint z, wxSize b)
{
	d = new wxButton(o, p, v, z, b);
	return d;
}