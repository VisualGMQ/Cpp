#include <wx/wx.h>
#include <iostream>
#include <string>
using namespace std;

enum TimerID{
    timer1
};

class MyFrame:public wxFrame{
public:
    MyFrame(string title):wxFrame(nullptr, wxID_ANY, title){
        timer = new wxTimer(this, timer1);  //产生一个wxTimer实例
        timer->Start(1000);
    }

    //Timer函数
    void OnTimer(wxTimerEvent& event){
        cout<<"timer triggered"<<endl;
    }
private:
    wxTimer* timer;
    wxDECLARE_EVENT_TABLE();
};

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_TIMER(timer1, MyFrame::OnTimer) //绑定到定时器函数
wxEND_EVENT_TABLE()

class MyApp:public wxApp{
public:
    bool OnInit(){
        frame = new MyFrame("timer");
        frame->Show();   
        return true;
    }
private:
    MyFrame* frame;
};

IMPLEMENT_APP(MyApp)