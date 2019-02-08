#include <wx/wx.h>
#include <wx/wxprec.h>
#include <iostream>
using namespace std;

class myApp:public wxApp{
public:
	virtual bool OnInit();	
};

IMPLEMENT_APP(myApp);

bool myApp::OnInit(){
	wxFrame* frame  = new wxFrame(nullptr,wxID_ANY,"hello",wxDefaultPosition,wxSize(700,700));
	frame->Center();
	frame->Show();
	return true;
}
