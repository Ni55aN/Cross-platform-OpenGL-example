#include <stdio.h>
#include <wx/wx.h>
#include <wx/glcanvas.h>
#define GLUT_DISABLE_ATEXIT_HACK
#include <GL/glut.h>



class GLCanvas : public wxGLCanvas
{
public:
    bool inited;
    
    GLUquadricObj * pointTool;
     
    wxSize size;
    wxWindow* parent;
    wxGLContext* ctx;
    GLuint Program;

    GLCanvas(wxWindow* par);
    ~GLCanvas();
     void onPaint(wxPaintEvent& event);
     void onIdle(wxIdleEvent& evt);
     void onSize(wxSizeEvent& event);
     const char*  loadSources(const char* path);
     
     void init();
     void render();
     void updateProjection();
     void ShaderLoWg(unsigned int shader);

     
    void onMouseDown(wxMouseEvent& event); 
    void onMouseUp(wxMouseEvent& event);    
    void onMouseWheel(wxMouseEvent& event); 
    void onMouseDclick(wxMouseEvent& event);
    void onMouseMove(wxMouseEvent& event);
    
    
   // DECLARE_EVENT_TABLE();
};

GLCanvas::GLCanvas(wxWindow* par) :
size(wxDefaultSize),
parent(par),
wxGLCanvas(par, wxID_ANY, NULL, wxDefaultPosition, wxDefaultSize) {


    this->inited = false;

    this->Bind(wxEVT_IDLE, &GLCanvas::onIdle, this);
    this->Bind(wxEVT_PAINT, &GLCanvas::onPaint, this);
    this->Bind(wxEVT_SIZE, &GLCanvas::onSize, this);

    this->Bind(wxEVT_LEFT_DOWN, &GLCanvas::onMouseDown, this);
    this->Bind(wxEVT_MIDDLE_DOWN, &GLCanvas::onMouseDown, this);
    this->Bind(wxEVT_RIGHT_DOWN, &GLCanvas::onMouseDown, this);

    this->Bind(wxEVT_LEFT_UP, &GLCanvas::onMouseUp, this);
    this->Bind(wxEVT_MIDDLE_UP, &GLCanvas::onMouseUp, this);
    this->Bind(wxEVT_RIGHT_UP, &GLCanvas::onMouseUp, this);

    this->Bind(wxEVT_MOUSEWHEEL, &GLCanvas::onMouseWheel, this);

    this->Bind(wxEVT_LEFT_DCLICK, &GLCanvas::onMouseDclick, this);
    this->Bind(wxEVT_RIGHT_DCLICK, &GLCanvas::onMouseDclick, this);

    this->Bind(wxEVT_MOTION, &GLCanvas::onMouseMove, this);

    ctx = new wxGLContext(this);

    int argc = 1;
    char* argv[1] = {wxString((wxTheApp->argv)[0]).char_str()};

    glutInit(&argc, argv);

}

void GLCanvas::onMouseDown(wxMouseEvent& event) {

    wxPoint p = event.GetPosition();
}

void GLCanvas::onMouseUp(wxMouseEvent& event) {

    wxPoint p = event.GetPosition();
}

void GLCanvas::onMouseWheel(wxMouseEvent& event) {

}

void GLCanvas::onMouseDclick(wxMouseEvent& event) {


    wxPoint p = event.GetPosition();

}

void GLCanvas::onMouseMove(wxMouseEvent& event) {

    wxPoint p = event.GetPosition();
}

GLCanvas::~GLCanvas() {
}

void GLCanvas::init() {

    SetCurrent(*ctx);
    wxClientDC(this);
    this->inited = true;

}

float red=0, green = 0., blue = 0;

void GLCanvas::render() {

    if (!inited)return;

    SetCurrent(*ctx);
    //  wxPaintDC(this);
    wxClientDC(this);
	

	red+=0.005;
	green+=0.01;
	blue+=0.001;

	if(red>1.0)red=0.0;
	if(green>1.0)green=0.0;
	if(blue>1.0)blue=0.0;

	
	glClearColor(red,green,blue,1.0);
	glClear(GL_COLOR_BUFFER_BIT);


    glFlush();
    SwapBuffers();
}

void GLCanvas::onPaint(wxPaintEvent& event) {

    this->render();
}

void GLCanvas::updateProjection() {

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();


    gluPerspective(30.0f, size.GetWidth() / size.GetHeight(), 0.01f, 100.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);


}

void GLCanvas::onSize(wxSizeEvent& event) {

    if (!inited)return;

    SetCurrent(*ctx);

    parent->GetSize();
    SetSize(size.GetWidth(), size.GetHeight());

}

void GLCanvas::onIdle(wxIdleEvent& evt) {
    this->render();
    evt.RequestMore();
}

class MyFrame : public wxFrame {
    GLCanvas* canvas;

public:

    MyFrame() : wxFrame(NULL, wxID_ANY, "Hello World") {
        wxMenu *menuFile = new wxMenu;
        menuFile->AppendSeparator();
        menuFile->Append(wxID_EXIT);
        wxMenu *menuHelp = new wxMenu;
        menuHelp->Append(wxID_ABOUT);
        wxMenuBar *menuBar = new wxMenuBar;
        menuBar->Append(menuFile, "&File");
        menuBar->Append(menuHelp, "&Help");
        SetMenuBar(menuBar);

        this->Connect(wxEVT_SHOW, wxShowEventHandler(MyFrame::onShow), NULL, this);


        canvas = new GLCanvas(this);
    }

    void onShow(wxShowEvent& evt) {



        canvas->init();


    }

};

class MyApp : public wxApp {
public:

    bool OnInit() {

        MyFrame *frame = new MyFrame();
        frame->Show(true);

        this->Bind(wxEVT_KEY_DOWN, &MyApp::onKeyDown, this);
        this->Bind(wxEVT_KEY_UP, &MyApp::onKeyUp, this);

        return true;
    }

private:

    void onKeyDown(wxKeyEvent& event) {

    }

    void onKeyUp(wxKeyEvent& event) {

    }
};


wxIMPLEMENT_APP(MyApp);
