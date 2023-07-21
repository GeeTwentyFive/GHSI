#pragma once


#include "FL/Fl.H"


#include "Widgets/InstallWindow/InstallWindow.h"
#include "Widgets/InstallWindow/InstallButton/InstallButton.h"
#include "Widgets/InstallWindow/SteamPathInputBox/SteamPathInputBox.h"




#define SCREEN_WIDTH Fl::w()
#define SCREEN_HEIGHT Fl::h()








#define INSTALL_WINDOW_WIDTH 640
#define INSTALL_WINDOW_HEIGHT 360
#define INSTALL_WINDOW_TITLE "Gee's Hidden: Source Installer"


#define INSTALL_BUTTON_CENTERX (INSTALL_WINDOW_WIDTH / 2)
#define INSTALL_BUTTON_CENTERY (INSTALL_WINDOW_HEIGHT - (INSTALL_WINDOW_HEIGHT / 8))
#define INSTALL_BUTTON_LABEL "Install"


#define STEAM_PATH_INPUT_DEFAULT "C:\\Program Files (x86)\\Steam"
#define STEAM_PATH_INPUT_WIDTH (INSTALL_WINDOW_WIDTH - (INSTALL_WINDOW_WIDTH / 8))
#define STEAM_PATH_INPUT_HEIGHT 50
#define STEAM_PATH_INPUT_X ((INSTALL_WINDOW_WIDTH / 2) - (STEAM_PATH_INPUT_WIDTH / 2))
#define STEAM_PATH_INPUT_Y ((INSTALL_WINDOW_HEIGHT / 2) - STEAM_PATH_INPUT_HEIGHT)








void InitializeGUI();


void SetInstallButtonCallback(Fl_Callback cb);


int StartGUI();