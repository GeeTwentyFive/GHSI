#pragma once


#include <Windows.h>


#include "../GUI/Widgets/InstallWindow/SteamPathInputBox/SteamPathInputBox.h"

#include "include/DownloadGame.h"
#include "include/ExtractGameFiles.h"
#include "include/ModifyGameFiles.h"
#include "include/InstallSourceSDKBase2006.h"
#include "include/InstallGame.h"




#define DOWNLOAD_SERVER "https://www.moddb.com"
#define DOWNLOAD_URL "https://www.moddb.com/downloads/start/8465"
#define DOWNLOAD_FILENAME "_HS.exe"




#define HS_EXTRACTED_DIRNAME "_HSGameFiles"




#define GAME_NAME "HIDDEN: SOURCE - Enhanced Edition"

#define CONFIG_NAME "GHS_config.cfg"




#define STEAM_PATH steamPathInput->value()




extern char tempFolderPath[MAX_PATH];

extern char downloadPath[MAX_PATH];




void PrintToConsole(const char* input);




void InstallHiddenSource(const char* steamBaseDir);