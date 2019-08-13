#include "wx/wx.h"
#include <string>
#include <iostream>
using namespace std;

class Canva:public wxPanel{
public:
    Canva(wxFrame* parent):wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(800, 800)){
    }
    //绘图函数，所有的绘图功能都得在这里进行
    void OnPaint(wxPaintEvent &event) {
        wxClientDC dc(this); //首先获得wxPaintDC
        dc.SetPen(*wxBLUE_PEN);
        dc.DrawLine(wxPoint(0, 0), wxPoint(100, 100));
        dc.SetBrush(*wxGREEN_BRUSH);
        dc.SetPen(*wxGREY_PEN);
        dc.DrawRectangle(wxPoint(200, 200), wxSize(100, 200));
        //对文字需要特殊的操作才能改变外貌
        dc.SetTextForeground(wxColour(200, 100, 100));   //改变字体颜色
        dc.SetFont(wxFontInfo(20).Bold());
        dc.DrawText("this is a text", wxPoint(100, 100));
        wxInitAllImageHandlers();
        dc.DrawBitmap(wxBitmap("img.bmp", wxBITMAP_TYPE_ANY), wxPoint(300, 300));
    }
private:
    wxDECLARE_EVENT_TABLE();
};

wxBEGIN_EVENT_TABLE(Canva, wxPanel)
    EVT_PAINT(Canva::OnPaint)   //画布事件绑定
wxEND_EVENT_TABLE()

class MyFrame:public wxFrame{
public:
    MyFrame(string title):wxFrame(nullptr, -1, title, wxDefaultPosition, wxSize(500, 500)){
        canva = new Canva(this);
        canva->Show();
    }
private:
    Canva* canva;
    wxDECLARE_EVENT_TABLE();
};

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
wxEND_EVENT_TABLE()

class MyApp:public wxApp{
public:
    virtual bool OnInit();
private:
    MyFrame* frame;
};

bool MyApp::OnInit(){
    frame = new MyFrame("drawShape");
    frame->Show();
    return true;
}

IMPLEMENT_APP(MyApp);