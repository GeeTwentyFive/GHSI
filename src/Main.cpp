#include "GUI/GUI.h"
#include "Installer/Installer.h"




void InstallButton_Press(Fl_Widget*, void*);

int main() {

	InitializeGUI();


	SetInstallButtonCallback(InstallButton_Press);


	return StartGUI();

}




void InstallButton_Press(Fl_Widget* installButton, void*) {

	const char* path = steamPathInput->value();


	if (!fl_filename_isdir(path)) {

		MessageBoxA(NULL, "ERROR: Invalid path", "Error!", (MB_OK | MB_ICONERROR));

	}


	else {

		installButton->deactivate();

		steamPathInput->deactivate();

		steamPathInputBrowseButton->deactivate();

		InstallHiddenSource(path);

	}

}