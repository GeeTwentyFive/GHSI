#include "SteamPathInputBox.h"




Fl_Output* steamPathInputLabel;
void InitializeSteamPathInputLabel();


Fl_Button* steamPathInputBrowseButton;
Fl_Native_File_Chooser* fileChooser;
void InitializeSteamPathInputBrowseButton();




Fl_File_Input* steamPathInput;


void InitializeSteamPathInputBox() {

	steamPathInput = new Fl_File_Input(STEAM_PATH_INPUT_X, STEAM_PATH_INPUT_Y, STEAM_PATH_INPUT_WIDTH, STEAM_PATH_INPUT_HEIGHT);

	steamPathInput->value(STEAM_PATH_INPUT_DEFAULT);

	steamPathInput->textsize(STEAM_PATH_INPUT_TEXTSIZE);




	InitializeSteamPathInputLabel();

	InitializeSteamPathInputBrowseButton();

}








void InitializeSteamPathInputLabel() {

	steamPathInputLabel = new Fl_Output(STEAM_PATH_INPUT_LABEL_X, STEAM_PATH_INPUT_LABEL_Y, STEAM_PATH_INPUT_LABEL_WIDTH, STEAM_PATH_INPUT_LABEL_HEIGHT);

	steamPathInputLabel->value(STEAM_PATH_INPUT_LABEL_TEXT);

	steamPathInputLabel->textsize(STEAM_PATH_INPUT_LABEL_TEXTSIZE);

	steamPathInputLabel->textcolor(STEAM_PATH_INPUT_LABEL_TEXTCOLOR);

	steamPathInputLabel->color(STEAM_PATH_INPUT_LABEL_BGCOLOR);

	steamPathInputLabel->box(FL_NO_BOX);

}




void SteamPathInputBrowseButton_Press(Fl_Widget*, void*);


void InitializeSteamPathInputBrowseButton() {

	steamPathInputBrowseButton = new Fl_Button(STEAM_PATH_INPUT_BROWSE_BUTTON_X, STEAM_PATH_INPUT_BROWSE_BUTTON_Y, STEAM_PATH_INPUT_BROWSE_BUTTON_WIDTH, STEAM_PATH_INPUT_BROWSE_BUTTON_HEIGHT, STEAM_PATH_INPUT_BROWSE_BUTTON_LABEL);

	steamPathInputBrowseButton->labelsize(STEAM_PATH_INPUT_BROWSE_BUTTON_LABELSIZE);

	steamPathInputBrowseButton->callback(SteamPathInputBrowseButton_Press);

}


void SteamPathInputBrowseButton_Press(Fl_Widget*, void*) {

	fileChooser = new Fl_Native_File_Chooser();

	fileChooser->type(1);

	fileChooser->title(FILE_CHOOSER_TITLE);

	if (fileChooser->show() == 0) {

		steamPathInput->value(fileChooser->filename());

	}

}