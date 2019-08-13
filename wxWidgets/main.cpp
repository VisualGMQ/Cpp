#include "wx/wx.h"
#include "wx/sizer.h"
#include "wx/wrapsizer.h"
#include <iostream>
using namespace std;

/*
class myFrame:public wxFrame{
public:
    myFrame(const wxString& title):wxFrame(nullptr, -1, title){
        wxPanel* panel = new wxPanel(this, wxID_ANY);
        panel->Show();
    }
private:
    wxDECLARE_EVENT_TABLE();
};

wxBEGIN_EVENT_TABLE(myFrame, wxFrame)
wxEND_EVENT_TABLE()
*/

class myApp:public wxApp{
public:
    bool OnInit() override {
        //myFrame* frame = new myFrame("wxBoxSizer");
        wxFrame* frame = new wxFrame(nullptr, -1, "hello world");
        frame->Show();
        return true;
    }
};

IMPLEMENT_APP(myApp);