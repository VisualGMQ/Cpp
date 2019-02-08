#include <iostream>
#include <wx/wx.h>
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
		cout<<"布局有很多种，在不使用布局器的情况下你可以使用绝对位置，这个时候你可以指定控件的位置（以像素为单位）。但是窗口大小改变的时候控件位置不会改变，所以一般不会使用绝对位置"<<endl;
		cout<<"布局之间可以相互嵌套"<<endl;
		cout<<"wxBoxSizer布局允许你的空间在一条直线上"<<endl;
		wxStaticText* st = new wxStaticText(this,wxID_ANY,"我使用的是绝对位置",wxPoint(0,0),wxSize(200,50));	
		wxBoxSizer* boxsizer = new wxBoxSizer(wxHORIZONTAL);
		wxButton* b1 = new wxButton(this,wxID_ANY,"button1");
		wxButton* b2 = new wxButton(this,wxID_ANY,"button2");
		wxButton* b3 = new wxButton(this,wxID_ANY,"button3");
		boxsizer->Add(b1,0,wxALL,5);
		boxsizer->Add(b2,1,wxALL,5);
		boxsizer->Add(b3,2,wxALL,5);

		SetSizer(boxsizer);
		Center();
}

bool myApp::OnInit(){
		myFrame* frame = new myFrame("layout",wxSize(500,500));
		frame->Show(true);
		return true;
}
