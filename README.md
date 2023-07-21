This program uses 7z.dll and 7z.exe

[7Zip License](https://www.7-zip.org/license.txt)

# Usage
1) Run the compiled executable
2) Enter path to Steam base directory \(Example: "C:\Program Files \(x86\)\Steam"\)
3) Click "Install" button
4) \(Situational\) If you do not have Source SDK Base 2006 installed, you will be prompted to install it on Steam during execution of this installer. Install it.

# Building
This program was made with Visual Studio 2022 on Windows 10

Dependencies: FLTK 1.3.8

In project settings:
- Set additional include directories to "\<project directory\>/libs/fltk"
- \-------------------------------------------------------------------------------------------------
- Set additional library path for DEBUG to "\<project directory\>/libs/fltk/lib/Debug"
- Set additional library path for RELEASE to "\<project directory\>/libs/fltk/lib/Release"
- \-------------------------------------------------------------------------------------------------
- In Linker->Input add the following libraries for DEBUG: fltkd.lib msvcrtd.lib Urlmon.lib
- In Linker->Input add the following libraries for RELEASE: fltk.lib msvcrt.lib Urlmon.lib
