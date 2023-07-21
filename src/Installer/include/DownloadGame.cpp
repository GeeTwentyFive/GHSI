#include "DownloadGame.h"




class DownloadStatus : public IBindStatusCallback {

public:
    virtual HRESULT STDMETHODCALLTYPE QueryInterface(
        /* [in] */ REFIID riid,
        /* [iid_is][out] */ _COM_Outptr_ void __RPC_FAR* __RPC_FAR* ppvObject) {
        return NULL;
    }

    virtual ULONG STDMETHODCALLTYPE AddRef(void) {
        return NULL;
    }

    virtual ULONG STDMETHODCALLTYPE Release(void) {
        return NULL;
    }


    virtual HRESULT STDMETHODCALLTYPE OnStartBinding(
        /* [in] */ DWORD dwReserved,
        /* [in] */ __RPC__in_opt IBinding* pib) {
        return NULL;
    }

    virtual HRESULT STDMETHODCALLTYPE GetPriority(
        /* [out] */ __RPC__out LONG* pnPriority) {
        return NULL;
    }

    virtual HRESULT STDMETHODCALLTYPE OnLowResource(
        /* [in] */ DWORD reserved) {
        return NULL;
    }

    virtual HRESULT STDMETHODCALLTYPE OnStopBinding(
        /* [in] */ HRESULT hresult,
        /* [unique][in] */ __RPC__in_opt LPCWSTR szError) {
        return NULL;
    }

    virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetBindInfo(
        /* [out] */ DWORD* grfBINDF,
        /* [unique][out][in] */ BINDINFO* pbindinfo) {
        return NULL;
    }

    virtual /* [local] */ HRESULT STDMETHODCALLTYPE OnDataAvailable(
        /* [in] */ DWORD grfBSCF,
        /* [in] */ DWORD dwSize,
        /* [in] */ FORMATETC* pformatetc,
        /* [in] */ STGMEDIUM* pstgmed) {
        return NULL;
    }

    virtual HRESULT STDMETHODCALLTYPE OnObjectAvailable(
        /* [in] */ __RPC__in REFIID riid,
        /* [iid_is][in] */ __RPC__in_opt IUnknown* punk) {
        return NULL;
    }








private:
	char progressOut[64] = { 0 };

public:
	virtual HRESULT __stdcall OnProgress(ULONG ulProgress, ULONG ulProgressMax, ULONG ulStatusCode, LPCWSTR szStatusText) {

        strcpy_s(progressOut, "");
        wsprintfA(progressOut, "%lu", ulProgress);


        strcat_s(progressOut, " of ");


        char buffer[32] = { 0 };
        wsprintfA(buffer, "%lu", ulProgressMax);
        strcat_s(progressOut, buffer);


        strcat_s(progressOut, "\n\0");




        PrintToConsole(progressOut);

        
        return S_OK;

	}

};


const char* ExtractDownloadURL(const char* url);
void Download(const char* url, const char* outPath);


void DownloadGameFiles() {

	strcpy_s(downloadPath, tempFolderPath);
	strcat_s(downloadPath, DOWNLOAD_FILENAME);


    char downloadMirrorURL[2048] = { 0 };
    strcpy_s(downloadMirrorURL, DOWNLOAD_SERVER);
    strcat_s(downloadMirrorURL, ExtractDownloadURL(DOWNLOAD_URL));

	
    Download(downloadMirrorURL, downloadPath);
    
}




void Download(const char* url, const char* outPath) {

    DownloadStatus downloadStatus;

    URLDownloadToFileA(NULL, url, outPath, NULL, &downloadStatus);

}
















void ExtractDownloadURL_Error();
const char* FindUrlInFileContents(const char* fileContents);


const char* ExtractDownloadURL(const char* url) {

    char urlDownloadPath[MAX_PATH] = { 0 };

    strcpy_s(urlDownloadPath, tempFolderPath);
    strcat_s(urlDownloadPath, "_DSite.html");


    Download(url, urlDownloadPath);




    char fileContents[8192] = { 0 };

    HANDLE hDSiteHtmlFile = CreateFileA(urlDownloadPath, GENERIC_READ, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    if (hDSiteHtmlFile == INVALID_HANDLE_VALUE) {

        ExtractDownloadURL_Error();

    }


    if (ReadFile(hDSiteHtmlFile, fileContents, 8000, NULL, NULL) == FALSE) {

        ExtractDownloadURL_Error();

    }


    CloseHandle(hDSiteHtmlFile);
    DeleteFileA(urlDownloadPath);


    return FindUrlInFileContents(fileContents);

}




void ExtractDownloadURL_Error() {

    MessageBoxA(NULL, "ERROR: Failed to extract Download URL", "Error!", (MB_OK | MB_ICONERROR | MB_TOPMOST));
    exit(1);

}




// If I initialize this variable inside of the function below, the program works in Debug configuration, but not in Release configuration.
// In Release the memory which this variable is refering to seems to be deallocated, but the returned pointer stays.
// So what happens is that the memory location which the pointer is pointing to ends up being not containing the desired return value (but various other stuff depending on what is written to that area of memory at the time).
char url[2048] = { 0 };

const char* FindUrlInFileContents(const char* fileContents) {

    const char* TARGET = "<p>Click to <a href=\"/downloads/mirror/8465/\0";
    const int URL_BEGIN_OFFSET = 21;


    for (int startPos = 0; startPos < strlen(fileContents); startPos++) {

        int correctCharsCounter = 0;
        
        for (int offset = 0; offset < strlen(TARGET); offset++) {

            if (fileContents[startPos + offset] == TARGET[offset]) {

                correctCharsCounter++;

            }

        }


        if (correctCharsCounter == strlen(TARGET)) {

            int fileContentsIndex = startPos + URL_BEGIN_OFFSET;
            int urlIndex = 0;

            while (fileContents[fileContentsIndex] != '"') {

                url[urlIndex] = fileContents[fileContentsIndex];

                fileContentsIndex++;
                urlIndex++;

            }


            url[urlIndex + 1] = '\0';


            break;

        }

    }




    if (url == NULL) {

        ExtractDownloadURL_Error();
        return 0;

    }


    else {

        return url;

    }

}