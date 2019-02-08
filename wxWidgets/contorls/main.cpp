#include <iostream>
#include <wx/wx.h>
#include <wx/propgrid/propgrid.h>
#include <wx/treectrl.h>
#include <wx/notebook.h>
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

enum Menu{
	M_OPEN=1,
	M_SAVE,
	M_SAVEAS,
	M_INFO
};

myFrame::myFrame(const wxString& title,const wxSize& size)
		:wxFrame(nullptr,-1,title,wxDefaultPosition,size){
		//wxMenu and wxMenuBar
		wxMenuBar* menubar = new wxMenuBar();
		wxMenu* filemenu = new wxMenu();
		wxMenu* infomenu = new wxMenu();
		filemenu->Append(M_OPEN,"&Open","Open file");
		filemenu->Append(M_SAVE,"&Save","Save file");
		filemenu->AppendSeparator();
		filemenu->Append(M_SAVEAS,"Sa&ve as","Save file as other");
		infomenu->Append(M_INFO,"&info","Show the info");
		menubar->Append(filemenu,"&File");
		menubar->Append(infomenu,"&Info");
		SetMenuBar(menubar);
		//wxStatusbar
		wxStatusBar* sb = CreateStatusBar();
		SetStatusBar(sb);
		//wxButton
		wxButton* button = new wxButton(this,wxID_ANY,"button",wxPoint(0,0),wxSize(100,50));
		//wxStaticText
		wxStaticText* st = new wxStaticText(this,wxID_ANY,"this is a static text",wxPoint(0,55));
		//wxTextCtrl
		wxTextCtrl* tc = new wxTextCtrl(this,wxID_ANY,"please input some text",wxPoint(0,110),wxSize(200,50));
		//wxComboBox
		wxArrayString arraystr;
		arraystr.Add("Option1");
		arraystr.Add("Option2");
		arraystr.Add("Option3");
		arraystr.Add("Option4");
		wxComboBox* cb = new wxComboBox(this,wxID_ANY,"comboBox",wxPoint(0,170),wxDefaultSize,arraystr);
		//wxSlider
		wxSlider* slider = new wxSlider(this,wxID_ANY,0,0,100,wxPoint(0,200),wxSize(200,50));
		//wxScrollBar
		wxScrollBar* scrollbar = new wxScrollBar(this,wxID_ANY,wxPoint(0,250));
		//wxTreeCtrl
		wxTreeCtrl* treectrl = new wxTreeCtrl(this,wxID_ANY,wxPoint(250,0),wxSize(220,250));
		wxTreeItemId rootID = treectrl->AddRoot("root");
		wxTreeItemId child1 = treectrl->AppendItem(rootID,"child1");
		treectrl->AppendItem(rootID,"child2");
		treectrl->AppendItem(child1,"child1-1");	
		treectrl->AppendItem(child1,"child1-2");	
		treectrl->AppendItem(child1,"child1-3");	
		//wxNotebook
		wxNotebook* nb =new wxNotebook(this,wxID_ANY,wxPoint(250,300),wxSize(300,250));
		wxPanel* panel1 = new wxPanel(nb,wxID_ANY);
		wxPanel* panel2 = new wxPanel(nb,wxID_ANY);
		wxPanel* panel3 = new wxPanel(nb,wxID_ANY);
		wxPanel* panel4 = new wxPanel(nb,wxID_ANY);
		nb->AddPage(panel1,"page1");	
		nb->AddPage(panel2,"page2");	
		nb->AddPage(panel3,"page3");	
		nb->AddPage(panel4,"page4");	
		//wxCheckBox
		wxCheckBox* chb = new wxCheckBox(this,wxID_ANY,"checkBox",wxPoint(0,300));
		//wxRadioBox
		wxArrayString as;
		as.Add("Radio1");
		as.Add("Radio2");
		as.Add("Radio3");
		wxRadioBox* box = new wxRadioBox(this,wxID_ANY,"RadioBox",wxPoint(0,400),wxSize(150,150),as);

		Center();
}

bool myApp::OnInit(){
	myFrame* frame = new myFrame("controls",wxSize(700,700));
	frame->Show(true);
	return true;
}
