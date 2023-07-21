#include "Button.h"




Button::Button(int centerX, int centerY, const char* label) {

	int selfCenteredXOffset = centerX - (width / 2);

	int selfCenteredYOffset = centerY - (height / 2);


	button = new Fl_Button(selfCenteredXOffset, selfCenteredYOffset, width, height, label);


	button->labelsize(labelSize);


	button->color(BUTTON_COLOR);


	button->box(FL_FLAT_BOX);

}




void Button::SetCallback(Fl_Callback callback) {

	button->callback(callback);

}