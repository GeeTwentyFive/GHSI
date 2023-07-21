#include "InstallButton.h"




Button* installButton;


void InitializeInstallButton() {

	installButton = new Button(INSTALL_BUTTON_CENTERX, INSTALL_BUTTON_CENTERY, INSTALL_BUTTON_LABEL);

}