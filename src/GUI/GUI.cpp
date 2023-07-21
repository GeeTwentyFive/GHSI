#include "GUI.h"




InstallWindow* installWindow;




void InitializeInstallWindow();




void InitializeGUI() {

	Fl::visible_focus(0);	// Removes the dotted line keyboard focus thing around some widgets (global)

	unsigned char iconData[] = { 100 };
	Fl_RGB_Image* icon = new Fl_RGB_Image(iconData, 1, 1, 1);
	Fl_Window::default_icon(icon);




	installWindow = new InstallWindow();

	InitializeInstallWindow();




	installWindow->Show();

}




int StartGUI() {

	return Fl::run();

}




void SetInstallButtonCallback(Fl_Callback cb) {

	installButton->SetCallback(cb);

}








void InitializeInstallWindow() {

	InitializeInstallButton();

	InitializeSteamPathInputBox();


	installWindow->EndGrouping();

}