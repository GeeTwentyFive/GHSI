#include "InstallGame.h"




void InstallGame() {

	const char* steamPath = STEAM_PATH;

	char hiddenInstallPath[MAX_PATH] = { 0 };
	strcpy_s(hiddenInstallPath, steamPath);

	if (steamPath[strlen(steamPath) - 1] != '\\') {

		strcat_s(hiddenInstallPath, "\\");

	}

	strcat_s(hiddenInstallPath, "steamapps\\sourcemods");




	char hiddenFolderPath[MAX_PATH] = { 0 };
	strcpy_s(hiddenFolderPath, hiddenInstallPath);
	strcat_s(hiddenFolderPath, "\\hidden");

	DWORD hiddenFolderAttribs = GetFileAttributesA(hiddenFolderPath);
	if (hiddenFolderAttribs & FILE_ATTRIBUTE_DIRECTORY) {
	
		char deletePrevHiddenFolderCommand[MAX_PATH * 2] = { "rmdir /S /Q \"" };
		strcat_s(deletePrevHiddenFolderCommand, hiddenFolderPath);
		strcat_s(deletePrevHiddenFolderCommand, "\"");

		system(deletePrevHiddenFolderCommand);
	
	};




	char gameFilesPath[MAX_PATH] = { 0 };
	strcpy_s(gameFilesPath, tempFolderPath);
	strcat_s(gameFilesPath, HS_EXTRACTED_DIRNAME);




	char hiddenInstallCommand[MAX_PATH * 3] = { "xcopy \"" };
	strcat_s(hiddenInstallCommand, gameFilesPath);
	strcat_s(hiddenInstallCommand, "\" \"");
	strcat_s(hiddenInstallCommand, hiddenInstallPath);
	strcat_s(hiddenInstallCommand, "\" /E /Y /I && rmdir /S /Q \"");
	strcat_s(hiddenInstallCommand, gameFilesPath);
	strcat_s(hiddenInstallCommand, "\"");


	system(hiddenInstallCommand);

}