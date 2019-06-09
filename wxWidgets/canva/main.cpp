#include "wx-3.0/wx/wx.h"
#include "wx-3.0/wx/wxhtml.h"

class myApp:public wxApp{
public:
    bool OnInit(){
        wxFrame* frame = new wxFrame(nullptr, -1, "test");
        wxButton* button = new wxButton(frame, -1, "test button");
        wxHtmlWindow* window = new wxHtmlWindow(frame, -1);
        window->LoadPage("./test.html");
        window->SetPage("htmlbody"
               "h1Error/h1"
               "Some error occurred :-H)"
               "/body/hmtl");
        window->Show();
        button->Show();
        frame->Show();
        return true;
    }
};

IMPLEMENT_APP(myApp);