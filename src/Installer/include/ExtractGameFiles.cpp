#include "ExtractGameFiles.h"




char szNSISArchivePath[MAX_PATH] = { 0 };
#define SZ_NSIS_ARCHIVE_FILENAME "7zNSIS.zip"

char szNSISFolderPath[MAX_PATH] = { 0 };
#define SZ_NSIS_FOLDER_NAME "7zNSIS"

char szNSISExePath[MAX_PATH] = { 0 };
#define SZ_NSIS_EXE "\\7z.exe"


char extractCommand[8191] = { 0 };




void _Init();
void Delete7zNSIS();


void ExtractGameFiles() {

	_Init();


	SetCurrentDirectoryA(tempFolderPath);
	system(extractCommand);


	Delete7zNSIS();

}




void Extract7zNSIS();

void _Init() {

	strcpy_s(szNSISArchivePath, tempFolderPath);
	strcat_s(szNSISArchivePath, SZ_NSIS_ARCHIVE_FILENAME);

	strcpy_s(szNSISFolderPath, tempFolderPath);
	strcat_s(szNSISFolderPath, SZ_NSIS_FOLDER_NAME);

	strcat_s(szNSISExePath, szNSISFolderPath);
	strcat_s(szNSISExePath, SZ_NSIS_EXE);




	strcpy_s(extractCommand, "\"");
	strcat_s(extractCommand, szNSISExePath);
	strcat_s(extractCommand, "\" x -y ");
	strcat_s(extractCommand, DOWNLOAD_FILENAME);
	strcat_s(extractCommand, " -o");
	strcat_s(extractCommand, HS_EXTRACTED_DIRNAME);




	Extract7zNSIS();


	DeleteFileA(szNSISArchivePath);

}








void Extract7zNSIS() {

	HANDLE h7zNSISArchive = CreateFileA(szNSISArchivePath, GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(h7zNSISArchive, raw7zNSISArchiveData, RAW_SZ_NSIS_ARCHIVE_DATA_SIZE, NULL, NULL);

	CloseHandle(h7zNSISArchive);


	char psUnzip[MAX_PATH * 3] = { "powershell -command \"Expand-Archive -Force '" };
	strcat_s(psUnzip, MAX_PATH * 3, szNSISArchivePath);
	strcat_s(psUnzip, MAX_PATH * 3, "' '");
	strcat_s(psUnzip, MAX_PATH * 3, tempFolderPath);
	strcat_s(psUnzip, MAX_PATH * 3, "'\"");
	system(psUnzip);

}




void Delete7zNSIS() {

	char delete7zNSISCommand[MAX_PATH * 2] = { "rmdir /S /Q \"" };
	strcat_s(delete7zNSISCommand, szNSISFolderPath);
	strcat_s(delete7zNSISCommand, "\"");

	system(delete7zNSISCommand);

}