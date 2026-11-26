const unsigned char EMBED__GAME_FILES_COMPRESSED_DATA[] = {
        #if !defined(__CLANGD__) && !defined(__INTELLISENSE__)
                #embed "build/embed/GameFiles.zip"
        #endif
};

const unsigned char EMBED__SOURCE_SDK_BASE_2006_PATCHES_COMPRESSED_DATA[] = {
        #if !defined(__CLANGD__) && !defined(__INTELLISENSE__)
                #embed "build/embed/SourceSDKBase2006_Patches.zip"
        #endif
};

#ifdef _WIN32
        const unsigned char EMBED__WINDOWS_GAME_LAUNCHER_DATA[] = {
                #if !defined(__CLANGD__) && !defined(__INTELLISENSE__)
                        #embed "embed/GHSLauncher.exe"
                #endif
        };
#endif