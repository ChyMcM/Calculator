#include "Calculator.h"
#include "ButtonFactory.h"
#include <sstream>
#include <iomanip>
Calculator::Calculator(const wxString& title, const wxPoint& pos, const wxSize& size) : wxFrame(NULL, 12345, title, pos, size)
{
    Center();
    wxMenu* menuFile = new wxMenu;
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenuBar* menuBar = new wxMenuBar;
    SetMenuBar(menuBar);
    display = new wxTextCtrl(this, -1, wxT("0"), wxPoint(0, 0), wxSize(250, 50), wxTE_READONLY);
    wxFont font = display->GetFont();
    font.SetPointSize(font.GetPointSize() + 5);
    display->SetFont(font);
    but0 = ButtonFactory::createButton(this, but0, 10000, "0", wxPoint(0, 50), wxSize(50, 50));
    but1 = ButtonFactory::createButton(this, but1, 10001, "1", wxPoint(50, 50), wxSize(50, 50));
    but2 = ButtonFactory::createButton(this, but2, 10002, "2", wxPoint(100, 50), wxSize(50, 50));
    but3 = ButtonFactory::createButton(this, but3, 10003, "3", wxPoint(150, 50), wxSize(50, 50));
    but4 = ButtonFactory::createButton(this, but4, 10004, "4", wxPoint(0, 100), wxSize(50, 50));
    but5 = ButtonFactory::createButton(this, but5, 10005, "5", wxPoint(50, 100), wxSize(50, 50));
    but6 = ButtonFactory::createButton(this, but6, 10006, "6", wxPoint(100, 100), wxSize(50, 50));
    but7 = ButtonFactory::createButton(this, but7, 10007, "7", wxPoint(150, 100), wxSize(50, 50));
    but8 = ButtonFactory::createButton(this, but8, 10008, "8", wxPoint(0, 150), wxSize(50, 50));
    but9 = ButtonFactory::createButton(this, but9, 10009, "9", wxPoint(50, 150), wxSize(50, 50));
    neg = ButtonFactory::createButton(this, neg, 10010, "(-)", wxPoint(100, 150), wxSize(50, 50));
    butequ = ButtonFactory::createButton(this, butequ, 10011, "=", wxPoint(150, 150), wxSize(50, 50));
    butadd = ButtonFactory::createButton(this, butadd, 10012, "+", wxPoint(0, 200), wxSize(50, 50));
    butsub = ButtonFactory::createButton(this, butsub, 10013, "-", wxPoint(50, 200), wxSize(50, 50));
    butdiv = ButtonFactory::createButton(this, butdiv, 10014, "/", wxPoint(100, 200), wxSize(50, 50));
    butmul = ButtonFactory::createButton(this, butmul, 10015, "*", wxPoint(150, 200), wxSize(50, 50));
    mod = ButtonFactory::createButton(this, mod, 10016, "%", wxPoint(0, 250), wxSize(50, 50));
    dec = ButtonFactory::createButton(this, dec, 10017, ".", wxPoint(50, 250), wxSize(50, 50));
    hex = ButtonFactory::createButton(this, hex, 10018, "Hex", wxPoint(100, 250), wxSize(50, 50));
    bin = ButtonFactory::createButton(this, bin, 10019, "Bin", wxPoint(150, 250), wxSize(50, 50));
    clear = ButtonFactory::createButton(this, clear, 10020, "Clear", wxPoint(200, 50), wxSize(50, 250));
    but0->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Calculator::OnButtonClick, this);
    but1->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Calculator::OnButtonClick, this);
    but2->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Calculator::OnButtonClick, this);
    but3->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Calculator::OnButtonClick, this);
    but4->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Calculator::OnButtonClick, this);
    but5->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Calculator::OnButtonClick, this);
    but6->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Calculator::OnButtonClick, this);
    but7->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Calculator::OnButtonClick, this);
    but8->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Calculator::OnButtonClick, this);
    but9->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Calculator::OnButtonClick, this);
    neg->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Calculator::OnButtonClick, this);
    butequ->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Calculator::OnButtonClick, this);
    butadd->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Calculator::OnButtonClick, this);
    butsub->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Calculator::OnButtonClick, this);
    butdiv->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Calculator::OnButtonClick, this);
    butmul->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Calculator::OnButtonClick, this);
    mod->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Calculator::OnButtonClick, this);
    dec->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Calculator::OnButtonClick, this);
    hex->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Calculator::OnButtonClick, this);
    bin->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Calculator::OnButtonClick, this);
    clear->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &Calculator::OnButtonClick, this);
}
void Calculator::OnButtonClick(wxCommandEvent& evt)
{
    int x = evt.GetId() - 10000;
    if (x == 0)
    {
        if (deci == true)
        {
            decita = decita / 10;
            if (op1on == true)
            {
                if (firstClick == true)
                {
                    dec2 = 0.0;
                }
                else
                {
                    dec2 = dec2 + (decita * 0);
                }
            }
            else if (firstClick == true)
            {
                dec1 = 0.0;
            }
            else
            {
                dec1 = dec1 + (decita * 0);
            }
        }
        else if (op1on == true)
        {
            if (firstClick == true)
            {
                num2 = 0;
            }
            else
            {
                num2 = (num2 * 10) + 0;
            }
        }
        else if (firstClick == true)
        {
            numo = 0;
        }
        else
        {
            numo = (numo * 10) + 0;
        }
        displayfeed += "0";
        firstClick = false;
        display->SetLabel(displayfeed);
        display->Refresh();
    }
    else if (x == 1)
    {
        if (deci == true)
        {
            decita = decita / 10;
            if (op1on == true)
            {
                if (firstClick == true)
                {
                    dec2 += .1;
                }
                else
                {
                    dec2 = dec2 + (decita * 1);
                }
            }
            else if (firstClick == true)
            {
                dec1 += .1;
            }
            else
            {
                dec1 = dec1 + (decita * 1);
            }
        }
        else if (op1on == true)
        {
            if (firstClick == true)
            {
                num2 = 1;
            }
            else
            {
                num2 = (num2 * 10) + 1;
            }
        }
        else if (firstClick == true)
        {
            numo = 1;
        }
        else
        {
            numo = (numo * 10) + 1;
        }
        displayfeed += "1";
        firstClick = false;
        display->SetLabel(displayfeed);
        display->Refresh();
    }
    else if (x == 2)
    {
    if (deci == true)
    {
        decita = decita / 10;
        if (op1on == true)
        {
            if (firstClick == true)
            {
                dec2 += .2;
            }
            else
            {
                dec2 = dec2 + (decita * 2);
            }
        }
        else if (firstClick == true)
        {
            dec1 += .2;
        }
        else
        {
            dec1 = dec1 + (decita * 2);
        }
    }
        else if (op1on == true)
        {
            if (firstClick == true)
            {
                num2 = 2;
            }
            else
            {
                num2 = (num2 * 10) + 2;
            }
        }
        else if (firstClick == true)
        {
            numo = 2;
        }
        else
        {
            numo = (numo * 10) + 2;
        }
        displayfeed += "2";
        firstClick = false;
        display->SetLabel(displayfeed);
        display->Refresh();
    }
    else if (x == 3)
    {
    if (deci == true)
    {
        decita = decita / 10;
        if (op1on == true)
        {
            if (firstClick == true)
            {
                dec2 += .3;
            }
            else
            {
                dec2 = dec2 + (decita * 3);
            }
        }
        else if (firstClick == true)
        {
            dec1 += .3;
        }
        else
        {
            dec1 = dec1 + (decita * 3);
        }
    }
        else if (op1on == true)
        {
            if (firstClick == true)
            {
                num2 = 3;
            }
            else
            {
                num2 = (num2 * 10) + 3;
            }
        }
        else if (firstClick == true)
        {
            numo = 3;
        }
        else
        {
            numo = (numo * 10) + 3;
        }
        displayfeed += "3";
        firstClick = false;
        display->SetLabel(displayfeed);
        display->Refresh();
    }
    else if (x == 4)
    {
    if (deci == true)
    {
        decita = decita / 10;
        if (op1on == true)
        {
            if (firstClick == true)
            {
                dec2 += .4;
            }
            else
            {
                dec2 = dec2 + (decita * 4);
            }
        }
        else if (firstClick == true)
        {
            dec1 += .4;
        }
        else
        {
            dec1 = dec1 + (decita * 4);
        }
    }
    else if (op1on == true)
    {
        if (firstClick == true)
        {
            num2 = 4;
        }
        else
        {
            num2 = (num2 * 10) + 4;
        }
    }
    else if (firstClick == true)
    {
        numo = 4;
    }
    else
    {
        numo = (numo * 10) + 4;
    }
    displayfeed += "4";
    firstClick = false;
    display->SetLabel(displayfeed);
    display->Refresh();
    }
    else if (x == 5)
    {
    if (deci == true)
    {
        decita = decita / 10;
        if (op1on == true)
        {
            if (firstClick == true)
            {
                dec2 += .5;
            }
            else
            {
                dec2 = dec2 + (decita * 5);
            }
        }
        else if (firstClick == true)
        {
            dec1 += .5;
        }
        else
        {
            dec1 = dec1 + (decita * 5);
        }
    }
    else if (op1on == true)
    {
        if (firstClick == true)
        {
            num2 = 5;
        }
        else
        {
            num2 = (num2 * 10) + 5;
        }
    }
    else if (firstClick == true)
    {
        numo = 5;
    }
    else
    {
        numo = (numo * 10) + 5;
    }
    displayfeed += "5";
    firstClick = false;
    display->SetLabel(displayfeed);
    display->Refresh();
    }
    else if (x == 6)
    {
    if (deci == true)
    {
        decita = decita / 10;
        if (op1on == true)
        {
            if (firstClick == true)
            {
                dec2 += .6;
            }
            else
            {
                dec2 = dec2 + (decita * 6);
            }
        }
        else if (firstClick == true)
        {
            dec1 += .6;
        }
        else
        {
            dec1 = dec1 + (decita * 6);
        }
    }
    else if (op1on == true)
    {
        if (firstClick == true)
        {
            num2 = 6;
        }
        else
        {
            num2 = (num2 * 10) + 6;
        }
    }
    else if (firstClick == true)
    {
        numo = 6;
    }
    else
    {
        numo = (numo * 10) + 6;
    }
    displayfeed += "6";
    firstClick = false;
    display->SetLabel(displayfeed);
    display->Refresh();
    }
    else if (x == 7)
    {
    if (deci == true)
    {
        decita = decita / 10;
        if (op1on == true)
        {
            if (firstClick == true)
            {
                dec2 += .7;
            }
            else
            {
                dec2 = dec2 + (decita * 7);
            }
        }
        else if (firstClick == true)
        {
            dec1 += .7;
        }
        else
        {
            dec1 = dec1 + (decita * 7);
        }
    }
    else if (op1on == true)
    {
        if (firstClick == true)
        {
            num2 = 7;
        }
        else
        {
            num2 = (num2 * 10) + 7;
        }
    }
    else if (firstClick == true)
    {
        numo = 7;
    }
    else
    {
        numo = (numo * 10) + 7;
    }
    displayfeed += "7";
    firstClick = false;
    display->SetLabel(displayfeed);
    display->Refresh();
    }
    else if (x == 8)
    {
    if (deci == true)
    {
        decita = decita / 10;
        if (op1on == true)
        {
            if (firstClick == true)
            {
                dec2 += .8;
            }
            else
            {
                dec2 = dec2 + (decita * 8);
            }
        }
        else if (firstClick == true)
        {
            dec1 += .8;
        }
        else
        {
            dec1 = dec1 + (decita * 8);
        }
    }
    else if (op1on == true)
    {
        if (firstClick == true)
        {
            num2 = 8;
        }
        else
        {
            num2 = (num2 * 10) + 8;
        }
    }
    else if (firstClick == true)
    {
        numo = 8;
    }
    else
    {
        numo = (numo * 10) + 8;
    }
    displayfeed += "8";
    firstClick = false;
    display->SetLabel(displayfeed);
    display->Refresh();
    }
    else if (x == 9)
    {
    if (deci == true)
    {
        decita = decita / 10;
        if (op1on == true)
        {
            if (firstClick == true)
            {
                dec2 += .9;
            }
            else
            {
                dec2 = dec2 + (decita * 9);
            }
        }
        else if (firstClick == true)
        {
            dec1 += .9;
        }
        else
        {
            dec1 = dec1 + (decita * 9);
        }
    }
    else if (op1on == true)
    {
        if (firstClick == true)
        {
            num2 = 9;
        }
        else
        {
            num2 = (num2 * 10) + 9;
        }
    }
    else if (firstClick == true)
    {
        numo = 9;
    }
    else
    {
        numo = (numo * 10) + 9;
    }
    displayfeed += "9";
    firstClick = false;
    display->SetLabel(displayfeed);
    display->Refresh();
    }
    else if (x == 10)
    {
        if (firstClick == true) {}
        else if (nega == false)
        {
            if (deci == true)
            {
                if (op1on == true)
                {
                    dec2 = -dec2;
                    if (add == true)
                    {
                        displayfeed = std::to_string(dec1) + "+(" + std::to_string(dec2) + ")";
                    }
                    else if (sub == true)
                    {
                        displayfeed = std::to_string(dec1) + "-(" + std::to_string(dec2) + ")";
                    }
                    else if (mult == true)
                    {
                        displayfeed = std::to_string(dec1) + "*(" + std::to_string(dec2) + ")";
                    }
                    else if (diva == true)
                    {
                        displayfeed = std::to_string(dec1) + "/(" + std::to_string(dec2) + ")";
                    }
                    else if (modu == true)
                    {
                        displayfeed = std::to_string(dec1) + "%(" + std::to_string(dec2) + ")";
                    }
                }
                else
                {
                    dec1 = -dec1;
                    displayfeed = "(" + std::to_string(dec1) + ")";
                }
            }
            else
            {
                if (op1on == true)
                {
                    num2 = -num2;
                    if (add == true)
                    {
                        displayfeed = std::to_string(numo) + "+(" + std::to_string(num2) + ")";
                    }
                    else if (sub == true)
                    {
                        displayfeed = std::to_string(numo) + "-(" + std::to_string(num2) + ")";
                    }
                    else if (mult == true)
                    {
                        displayfeed = std::to_string(numo) + "*(" + std::to_string(num2) + ")";
                    }
                    else if (diva == true)
                    {
                        displayfeed = std::to_string(numo) + "/(" + std::to_string(num2) + ")";
                    }
                    else if (modu == true)
                    {
                        displayfeed = std::to_string(numo) + "%(" + std::to_string(num2) + ")";
                    }
                }
                else
                {
                    numo = numo * -1;
                    displayfeed = "(" + std::to_string(numo) + ")";
                }
            }
        }
        else
        {
            if (deci == true)
            {
                if (op1on == true)
                {
                    dec2 = -dec2;
                    if (add == true)
                    {
                        displayfeed = std::to_string(dec1) + "+" + std::to_string(dec2);
                    }
                    else if (sub == true)
                    {
                        displayfeed = std::to_string(dec1) + "-" + std::to_string(dec2);
                    }
                    else if (mult == true)
                    {
                        displayfeed = std::to_string(dec1) + "*" + std::to_string(dec2);
                    }
                    else if (diva == true)
                    {
                        displayfeed = std::to_string(dec1) + "/" + std::to_string(dec2);
                    }
                    else if (modu == true)
                    {
                        displayfeed = std::to_string(dec1) + "%" + std::to_string(dec2);
                    }
                }
                else
                {
                    dec1 = -dec1;
                    displayfeed = std::to_string(dec1);
                }
            }
            else
            {
                if (op1on == true)
                {
                    num2 = -num2;
                    if (add == true)
                    {
                        displayfeed = std::to_string(numo) + "+" + std::to_string(num2);
                    }
                    else if (sub == true)
                    {
                        displayfeed = std::to_string(numo) + "-" + std::to_string(num2);
                    }
                    else if (mult == true)
                    {
                        displayfeed = std::to_string(numo) + "*" + std::to_string(num2);
                    }
                    else if (diva == true)
                    {
                        displayfeed = std::to_string(numo) + "/" + std::to_string(num2);
                    }
                    else if (modu == true)
                    {
                        displayfeed = std::to_string(numo) + "%" + std::to_string(num2);
                    }
                }
                else
                {
                    numo = -numo;
                    displayfeed = std::to_string(numo);
                }
            }
        }
        display->SetLabel(displayfeed);
        display->Refresh();
    }
    else if (x == 11)
    {
    if (binn == true || hexa == true)
    {
        displayfeed == "Error";
    }
domath:
        if (add == true)
        {
            if (deci == true)
            {
                decsum = dec1 + dec2;
                displayfeed = std::to_string(decsum);
                dec1 = decsum;

            }
            else
            {
                sum = numo + num2;
                numstor = sum;
                displayfeed = std::to_string(sum);
                numo = sum;
            }
            sum = 0;
            add = false;
        }
    else if (sub == true)
    {
            if (deci == true)
            {
                decsum = dec1 - dec2;
                displayfeed = std::to_string(decsum);
                dec1 = decsum;

            }
            else
            {
                sum = numo - num2;
                numstor = sum;
                displayfeed = std::to_string(sum);
                numo = sum;
            }
            sum = 0;
            sub = false;
    }
    else if (diva == true)
    {
            if (deci == true)
            {
                decsum = dec1 / dec2;
                displayfeed = std::to_string(decsum);
                dec1 = decsum;

            }
            else
            {
                sum = numo / num2;
                numstor = sum;
                displayfeed = std::to_string(sum);
                numo = sum;
            }
            sum = 0;
            diva = false;
    }
    else if (mult == true)
    {
            if (deci == true)
            {
                decsum = dec1 * dec2;
                displayfeed = std::to_string(decsum);
                dec1 = decsum;

            }
            else
            {
                sum = numo * num2;
                numstor = sum;
                displayfeed = std::to_string(sum);
                numo = sum;
            }
            sum = 0;
            mult = false;
    }
    else if (modu == true)
    {
            if (deci == true)
            {
                displayfeed = "Error";
                dec1 = 0;
            }
            else
            {
                sum = numo % num2;
                numstor = sum;
                displayfeed = std::to_string(sum);
                numo = sum;
            }
            sum = 0;
            modu = false;
    }
        if (binn == true)
        {
            goto makebin;
        }
        if (hexa == true)
        {
            goto makehex;
        }
        op1on = false;
        display->SetLabel(displayfeed);
        display->Refresh();
    }
    else if (x == 12)
    {
        if(firstClick == true)
        { }
        else
        {
            displayfeed += "+";
            add = true;
            op1on = true;
            firstClick = true;
        }
        display->SetLabel(displayfeed);
        display->Refresh();
    }
    else if (x == 13)
    {
    if (firstClick == true)
    {
    }
    else
    {
        displayfeed += "-";
        sub = true;
        op1on = true;
        firstClick = true;
    }
    display->SetLabel(displayfeed);
    display->Refresh();
    }
    else if (x == 14)
    {
    if (firstClick == true)
    {
    }
    else
    {
        displayfeed += "/";
        diva = true;
        op1on = true;
        firstClick = true;
    }
    display->SetLabel(displayfeed);
    display->Refresh();
    }
    else if (x == 15)
    {
    if (firstClick == true)
    {
    }
    else
    {
        displayfeed += "*";
        mult = true;
        op1on = true;
        firstClick = true;
    }
    display->SetLabel(displayfeed);
    display->Refresh();
    }
    else if (x == 16)
    {
    if (firstClick == true)
    {
    }
    else
    {
        displayfeed += "%";
        modu = true;
        op1on = true;
        firstClick = true;
    }
    display->SetLabel(displayfeed);
    display->Refresh();
    }
    else if (x == 17)
    {
    if (deci == true)
    {
        if (op1on == true)
        {
            numo = dec1;
            num2 = dec2;
        }
        else
        {
            numo = dec1;
        }
        deci = false;
       }
    else
    {
        if (op1on == true)
        {
            dec1 = numo;
            dec2 = num2;
        }
        else
        {
            dec1 = numo;
        }
        deci = true;
    }
    }
    else if (x == 18)
    {
    if (deci == true)
    {
        displayfeed = "Error";
       }
    if (op1on == true)
    {
        hexa == true;
        goto domath;
    }
    if (hexa == false)
    {
    makehex:
        std::ostringstream ss;
        ss << "0x" << std::setfill('0') << std::setw(8) << std::hex << numo;
        hexnum = ss.str();
        displayfeed = hexnum;
        hexa = true;
    }
    else
    {
        displayfeed = std::to_string(numo);
    }
    display->SetLabel(displayfeed);
    display->Refresh();
    hexnum.erase();
    }
    else if (x == 19)
    {
    if (deci == true)
    {
        displayfeed = "Error";
    }
    if (op1on == true)
    {
        binn = true;
        goto domath;
    }
    if (binn == false)
    {
makebin:
        num1 = numo;
            for (int i = 0; i < 32; i++)
            {
                if (num1 % 2 == 0)
                {
                    binnum = "0" + binnum;
                }
                else
                {
                    binnum = "1" + binnum;
                }
                num1 = num1 / 2;
            }
            displayfeed = binnum;
            binn = true;
    }
    else
    {
        displayfeed = std::to_string(numo);
    }
    display->SetLabel(displayfeed);
    display->Refresh();
    binnum.erase();
    }
    else
    {
    numo = 0;
    dec1 = 0;
    num2 = 0;
    dec2 = 0;
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
    displayfeed = "0";
    display->SetLabel(displayfeed);
    display->Refresh();
 }
}
void Calculator::OnExit(wxCommandEvent& event)
{
    Close(true);
}