#pragma once


#include "FL/Fl.H"
#include "FL/Fl_Button.H"




#define BUTTON_COLOR FL_WHITE




class Button {

private:
	int width = 200;
	int height = 50;
	int labelSize = 32;

	Fl_Button* button;




public:
	Button(int centerX, int centerY, const char* label);
	void SetCallback(Fl_Callback callback);

};