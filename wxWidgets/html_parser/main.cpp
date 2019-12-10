#include "wx/wx.h"
#include "wx/html/htmlwin.h"

class MyFrame:public wxFrame{
public:
    MyFrame():wxFrame(nullptr, -1, "test html"){
        window = new wxHtmlWindow(this);
        window->LoadPage("index.html");
        window->Show();
    }
private:
    wxHtmlWindow* window;
};

class MyApp:public wxApp{
public:
    bool OnInit(){
        MyFrame* frame = new MyFrame();
        frame->Show();
        return true;
    }
};

IMPLEMENT_APP(MyApp)