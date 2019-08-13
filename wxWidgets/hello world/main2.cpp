#include <wx/wx.h>
#include <iostream>
using namespace std;

enum ButtonID{
	button1
};

class myApp:public wxApp{
public:
	virtual bool OnInit();
};

class myFrame:public wxFrame{
public:
		myFrame(const wxString& title,const wxSize& size);
		void OnSize(wxSizeEvent& event){
			cout<<"resized"<<endl;
			wxSize size = event.GetSize();
			cout<<"new width is:"<<size.GetWidth()<<" new height is:"<<size.GetHeight()<<endl;
		}
		void OnButton(wxCommandEvent& event){
			cout<<button->GetLabel()<<endl;
		}
private:
		wxButton* button;
		wxDECLARE_EVENT_TABLE();
};

wxBEGIN_EVENT_TABLE(myFrame,wxFrame)
	EVT_SIZE(myFrame::OnSize)
	EVT_BUTTON(button1, myFrame::OnButton)
wxEND_EVENT_TABLE()

wxIMPLEMENT_APP(myApp);

myFrame::myFrame(const wxString& title,const wxSize& size)
		:wxFrame(nullptr,-1,title,wxDefaultPosition,size){
        /*
		wxMenuBar* menubar = new wxMenuBar;
	   	wxMenu* filemenu = new wxMenu;
		filemenu->Append(1,"&Hello","this is hello");
		filemenu->Append(2,"&Bye","this is bye");
		menubar->Append(filemenu,"file");
		SetMenuBar(menubar);
		*/
		button = new wxButton(this, button1, "this is a button");
		button->Show();
		CreateStatusBar();
		SetStatusText( "Welcome to wxWidgets!" );
}

bool myApp::OnInit(){
		myFrame* frame = new myFrame("hello world",wxSize(400,400));
		
		frame->Show(true);
		return true;
}