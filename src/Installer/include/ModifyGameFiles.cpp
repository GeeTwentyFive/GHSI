#include "ModifyGameFiles.h"
#include <Shlwapi.h>




void AddMaps();
void ModifyName();
void ModifyConfig();


void ModifyGameFiles() {

	AddMaps();

	ModifyName();

	ModifyConfig();

}








void AddMaps() {

	void* mapsArchiveData = NULL;
	DWORD mapsArchiveDataSize = 0;

	HRSRC hResource = FindResourceA(NULL, MAKEINTRESOURCEA(MAPS), "BINARY");
	HGLOBAL hGlobal = LoadResource(NULL, hResource);
	mapsArchiveDataSize = SizeofResource(NULL, hResource);
	mapsArchiveData = LockResource(hGlobal);








	char mapsArchivePath[MAX_PATH] = { 0 };
	strcat_s(mapsArchivePath, MAX_PATH, tempFolderPath);
	strcat_s(mapsArchivePath, MAX_PATH, "maps.zip\0");
	HANDLE hMapsArchive = CreateFileA(mapsArchivePath, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(hMapsArchive, mapsArchiveData, mapsArchiveDataSize, NULL, NULL);

	CloseHandle(hMapsArchive);








	char extractPath[MAX_PATH] = { 0 };
	strcpy_s(extractPath, tempFolderPath);
	strcat_s(extractPath, HS_EXTRACTED_DIRNAME);
	strcat_s(extractPath, "\\maps");




	char psUnzip[MAX_PATH * 3] = { "powershell -command \"Expand-Archive -Force '" };
	strcat_s(psUnzip, MAX_PATH * 3, mapsArchivePath);
	strcat_s(psUnzip, MAX_PATH * 3, "' '");
	strcat_s(psUnzip, MAX_PATH * 3, extractPath);
	strcat_s(psUnzip, MAX_PATH * 3, "'\"");
	system(psUnzip);


	DeleteFileA(mapsArchivePath);




	



	char mapsFolderPath[MAX_PATH] = {0};
	strcpy_s(mapsFolderPath, tempFolderPath);
	strcat_s(mapsFolderPath, HS_EXTRACTED_DIRNAME);
	strcat_s(mapsFolderPath, "\\hidden\\maps");


	char moveMapsCommands[MAX_PATH * 4] = { 0 };
	strcpy_s(moveMapsCommands, "copy /Y \"");
	strcat_s(moveMapsCommands, extractPath);
	strcat_s(moveMapsCommands, "\" \"");
	strcat_s(moveMapsCommands, mapsFolderPath);
	strcat_s(moveMapsCommands, "\" && rmdir /S /Q \"");
	strcat_s(moveMapsCommands, extractPath);
	strcat_s(moveMapsCommands, "\"");

	system(moveMapsCommands);

}








void ModifyName() {

	char targetFilePath[MAX_PATH] = { 0 };
	strcpy_s(targetFilePath, tempFolderPath);
	strcat_s(targetFilePath, HS_EXTRACTED_DIRNAME);
	strcat_s(targetFilePath, "\\hidden\\gameinfo.txt");


	char targetFileData[2048];
	const int targetFileSize = 1758;

	char targetFileBegin[2048];
	char targetFileEnd[2048];


	const int startOffset = 24;
	const int endOffset = 46;


	char targetFileDataOut[2048];




	HANDLE hTargetFile = CreateFileA(targetFilePath, GENERIC_READ, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(hTargetFile, targetFileData, targetFileSize, NULL, NULL);

	CloseHandle(hTargetFile);




	for (int i = 0; i < startOffset; i++) {

		targetFileBegin[i] = targetFileData[i];

	}

	targetFileBegin[startOffset] = '\0';
	

	for (int i = 0; i < targetFileSize - endOffset; i++) {

		targetFileEnd[i] = targetFileData[i + endOffset];

	}

	targetFileEnd[targetFileSize - endOffset] = '\0';




	strcpy_s(targetFileDataOut, targetFileBegin);
	strcat_s(targetFileDataOut, GAME_NAME);
	strcat_s(targetFileDataOut, targetFileEnd);




	DeleteFileA(targetFilePath);


	HANDLE hTargetFileOut = CreateFileA(targetFilePath, GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(hTargetFileOut, targetFileDataOut, strlen(targetFileDataOut), NULL, NULL);

	CloseHandle(hTargetFileOut);

}








void ModifyConfig() {

	char configOutputPath[MAX_PATH] = { 0 };
	strcpy_s(configOutputPath, tempFolderPath);
	strcat_s(configOutputPath, HS_EXTRACTED_DIRNAME);
	strcat_s(configOutputPath, "\\hidden\\cfg\\");
	strcat_s(configOutputPath, CONFIG_NAME);


	HANDLE hConfigOutFile = CreateFileA(configOutputPath, GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(hConfigOutFile, rawConfigData, RAW_CONFIG_DATA_SIZE, NULL, NULL);

	CloseHandle(hConfigOutFile);




	char defaultConfigPath[MAX_PATH] = { 0 };
	strcpy_s(defaultConfigPath, tempFolderPath);
	strcat_s(defaultConfigPath, HS_EXTRACTED_DIRNAME);
	strcat_s(defaultConfigPath, "\\hidden\\cfg\\");
	strcat_s(defaultConfigPath, "config_default.cfg");


	char defaultConfigData[8192] = { 0 };


	HANDLE hDefaultConfigFile = CreateFileA(defaultConfigPath, GENERIC_READ, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);


	DWORD defaultConfigFileSize = GetFileSize(hDefaultConfigFile, NULL);


	ReadFile(hDefaultConfigFile, defaultConfigData, defaultConfigFileSize, NULL, NULL);


	CloseHandle(hDefaultConfigFile);




	DeleteFileA(defaultConfigPath);




	char defaultConfigGHSConfigExecCommand[64] = { "\nexec " };
	strcat_s(defaultConfigGHSConfigExecCommand, CONFIG_NAME);

	defaultConfigData[defaultConfigFileSize] = '\0';
	strcat_s(defaultConfigData, defaultConfigGHSConfigExecCommand);


	hDefaultConfigFile = CreateFileA(defaultConfigPath, GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);


	WriteFile(hDefaultConfigFile, defaultConfigData, strlen(defaultConfigData), NULL, NULL);


	CloseHandle(hDefaultConfigFile);

}