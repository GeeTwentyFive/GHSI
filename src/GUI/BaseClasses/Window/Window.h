#pragma once


#include "FL/Fl.H"
#include "FL/Fl_Window.H"


#undef CreateWindow

#define SCREEN_WIDTH Fl::w()
#define SCREEN_HEIGHT Fl::h()


#define WINDOW_COLOR FL_BLACK




class Window {

public:
	void EndGrouping();
	void Show();
	void Center();




protected:
	Fl_Window* window;


protected:
	void CreateWindow(int w, int h, const char* title);

};