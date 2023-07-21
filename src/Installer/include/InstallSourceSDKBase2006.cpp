#include "InstallSourceSDKBase2006.h"




bool IsSSDKBase2006Installed();




void InstallSourceSDKBase2006() {

	if (IsSSDKBase2006Installed() == false) {

		ShellExecuteA(NULL, "open\0", "steam://install/215\0", NULL, NULL, SW_SHOW);

		MessageBoxW(NULL, L"Install \"Source SDK Base 2006\" on Steam.\nPress OK after installation has completed.", L"Attention!", (MB_OK | MB_ICONEXCLAMATION | MB_TOPMOST));

	}

}








bool IsSSDKBase2006Installed() {

	const char* steamPath = STEAM_PATH;

	char SSDKBase2006hl2exePath[MAX_PATH] = { 0 };
	strcpy_s(SSDKBase2006hl2exePath, steamPath);

	if (steamPath[strlen(steamPath) - 1] != '\\') {

		strcat_s(SSDKBase2006hl2exePath, "\\");

	}

	strcat_s(SSDKBase2006hl2exePath, "steamapps\\common\\Source SDK Base\\hl2.exe");




	DWORD hl2exeFileAttrib = GetFileAttributesA(SSDKBase2006hl2exePath);


	if (hl2exeFileAttrib == INVALID_FILE_ATTRIBUTES) {

		char message[MAX_PATH * 4] = { "\nSource SDK Base 2006 hl2.exe not found in " };
		strcat_s(message, SSDKBase2006hl2exePath);
		strcat_s(message, "\nSource SDK Base 2006 is required for Hidden: Source to work as intended\n");

		PrintToConsole(message);


		return false;

	}

	else {

		return true;

	}

}