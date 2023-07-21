#include "Installer.h"




char tempFolderPath[MAX_PATH] = { 0 };
char downloadPath[MAX_PATH] = { 0 };




void PrintToConsole(const char* input) {

	WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE), input, strlen(input), NULL, NULL);

}




void Init();


void InstallHiddenSource(const char* steamBaseDir) {

	Init();


	PrintToConsole("\nDownloading game files...\n");
	DownloadGameFiles();

	PrintToConsole("\nExtracting game files...\n");
	ExtractGameFiles();

	DeleteFileA(downloadPath);

	PrintToConsole("\nOptimizing settings and installing maps...\n");
	ModifyGameFiles();

	InstallSourceSDKBase2006();

	PrintToConsole("\nExiting Steam...\n");
	system("taskkill /F /IM Steam.exe");
	PrintToConsole("(Ignore error if Steam was not running)\n");

	PrintToConsole("\nInstalling Hidden: Source - Enhanced Edition...\n");
	InstallGame();


	MessageBoxA(NULL, "Installation completed!", "Success!", (MB_OK | MB_ICONINFORMATION | MB_TOPMOST));
	exit(0);

}




void Init() {

	AllocConsole();


	GetTempPathA(MAX_PATH, tempFolderPath);

}