#include <wx/wx.h>
#include <iostream>
using namespace std;

class myApp:public wxApp{
public:
	virtual bool OnInit();
};

class myFrame:public wxFrame{
public:
		myFrame(const wxString& title,const wxSize& size);
private:
		wxDECLARE_EVENT_TABLE();
};

wxBEGIN_EVENT_TABLE(myFrame,wxFrame)
wxEND_EVENT_TABLE()

wxIMPLEMENT_APP(myApp);

myFrame::myFrame(const wxString& title,const wxSize& size)
		:wxFrame(nullptr,-1,title,wxDefaultPosition,size){
		wxMenuBar* menubar = new wxMenuBar;
	   	wxMenu* filemenu = new wxMenu;
		filemenu->Append(1,"&Hello","this is hello");
		filemenu->Append(2,"&Bye","this is bye");
		menubar->Append(filemenu,"file");
		SetMenuBar(menubar);
		CreateStatusBar();
		SetStatusText( "Welcome to wxWidgets!" );
}

bool myApp::OnInit(){
		myFrame* frame = new myFrame("hello world",wxSize(400,400));
		
		frame->Show(true);
		return true;
}