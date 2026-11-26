#include <string>
#include <stdexcept>
#include <iostream>
#include <filesystem>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

#include <zip.h>

#if !defined(_WIN32) && !defined(__linux__)
        #error "Unsupported platform"
#endif

#ifdef _WIN32
        #define WIN32_LEAN_AND_MEAN
        #include <Windows.h>
        #include <shlobj.h>
#endif


#define ERROR(msg) throw std::runtime_error(std::string("[ERROR] ") + "@" + std::to_string(__LINE__) + " : " + (msg))


#include "embed.h"

int main() { try {
        std::string steam_dir_path; { steam_dir_path.reserve(4096);
                #ifdef _WIN32
                        DWORD _steam_dir_path_len = steam_dir_path.capacity();
                        char _steam_dir_path[_steam_dir_path_len];
                        {LSTATUS status = RegGetValueA(HKEY_CURRENT_USER,
                                "Software\\Valve\\Steam",
                                "SteamPath", RRF_RT_REG_SZ, NULL, _steam_dir_path, &_steam_dir_path_len
                        ); if (status != ERROR_SUCCESS) ERROR(std::string("Failed to get SteamPath from Windows registry\nGetLastError(): ") + std::to_string(GetLastError())); }
                        steam_dir_path = _steam_dir_path;
                #else
                        const char* home_dir = getenv("HOME"); if (home_dir == NULL) ERROR("Failed to get user's home directory");
                        steam_dir_path = home_dir;
                        steam_dir_path += "/.steam/steam";
                #endif
        } if (!std::filesystem::is_directory(steam_dir_path)) ERROR(std::string("Failed to find Steam's base directory at path '") + steam_dir_path + "' (...is Steam installed...?)");


        std::cout << "Patching Source SDK Base 2006..." << std::endl;

        const std::string source_sdk_base_dir_path = steam_dir_path + "/steamapps/common/Source SDK Base";
        if (!std::filesystem::is_directory(source_sdk_base_dir_path)) {
                #ifdef _WIN32
                        system("explorer steam://install/215");
                #else
                        system("steam steam://install/215 &> /dev/null &");
                #endif
                ERROR(std::string() +
                        "Source SDK Base 2006 dir not found at path '" + source_sdk_base_dir_path + "'\n\n"
                        "INSTALL 'Source SDK Base 2006' ON STEAM, THEN RE-RUN *AFTER* 'Source SDK Base 2006' IS INSTALLED"
                );
        }

        {int status = zip_stream_extract(
                (char*)EMBED__SOURCE_SDK_BASE_2006_PATCHES_COMPRESSED_DATA, sizeof(EMBED__SOURCE_SDK_BASE_2006_PATCHES_COMPRESSED_DATA),
                source_sdk_base_dir_path.data(), NULL, NULL
        ); if (status != 0) ERROR(std::string("Failed to extract Source SDK Base 2006 patches to '") + source_sdk_base_dir_path + "'\n^ 'kuba--/zip' error code: " + std::to_string(status));}


        std::cout << "Installing Hidden: Source - Enhanced Edition..." << std::endl;

        const std::string sourcemods_dir_path = steam_dir_path + "/steamapps/sourcemods"; if (!std::filesystem::is_directory(sourcemods_dir_path)) ERROR(std::string("sourcemods dir not found at path '") + sourcemods_dir_path + '\'');
        {int status = zip_stream_extract(
                (char*)EMBED__GAME_FILES_COMPRESSED_DATA, sizeof(EMBED__GAME_FILES_COMPRESSED_DATA),
                sourcemods_dir_path.data(), NULL, NULL
        ); if (status != 0) ERROR(std::string("Failed to extract game files to '") + sourcemods_dir_path + "'\n^ 'kuba--/zip' error code: " + std::to_string(status));}


        #ifdef _WIN32
                std::cout << "Extracting GHSLauncher.exe to Desktop..." << std::endl;

                char desktop_path[MAX_PATH]; {
                        {HRESULT result = SHGetFolderPathA(NULL,
                                CSIDL_DESKTOP, NULL, SHGFP_TYPE_CURRENT,
                                (char*)desktop_path
                        ); if (result != S_OK) ERROR(std::string("Failed to get path to Desktop via Win32 SHGetFolderPathA()\n^ HRESULT: ") + std::to_string(result)); }
                }
                std::ofstream(std::string(desktop_path) + "/GHSLauncher.exe", (std::ios::binary | std::ios::out)).write(
                        (char*)EMBED__WINDOWS_GAME_LAUNCHER_DATA, sizeof(EMBED__WINDOWS_GAME_LAUNCHER_DATA)
                );
        #endif


        #ifdef _WIN32
                system("explorer steam://exit");
        #else
                system("steam steam://exit &> /dev/null &");
        #endif

        std::cout << "Done!"
        #ifdef _WIN32
                << "\nUse 'GHSLauncher.exe' (on your Desktop) to launch the game"
        #endif
        << std::endl;
std::cout << "Press ENTER to continue..." << std::endl; getchar(); return 0; } catch (const std::exception& e) { std::cout << e.what() << std::endl << "Press ENTER to continue..." << std::endl; getchar(); return 1; } }