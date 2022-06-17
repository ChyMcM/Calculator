#include "ButtonFactory.h"
#include "Calculator.h"
#include "Main.h"
void ButtonFactory::createButton(wxWindow* o, wxButton* d, int p, wxString v, wxPoint z, wxSize b)
{
	d = new wxButton(o, p, v, z, b);
}