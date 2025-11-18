import platform
if (
        platform.system() != "Windows" and
        platform.system() != "Linux"
):
        raise OSError("ERROR: Unsupported OS")
if platform.system() == "Windows": import winreg
import os
import sys
import psutil


STEAM_PROCESS_NAME = "steam.exe" if platform.system() == "Windows" else "steam"


def install(appid: int, steamapps_install_dir_name: str):
        for p in psutil.process_iter(['name']):
                if p.name() == STEAM_PROCESS_NAME: p.kill()

        if platform.system() == "Windows":
                steamapps_dir = winreg.QueryValueEx(
                        winreg.OpenKey(winreg.HKEY_CURRENT_USER, "Software\\Valve\\Steam"),
                        "SteamPath"
                )[0] + "\\steamapps"
        else: steamapps_dir = os.path.expanduser("~/.steam/steam/steamapps")

        OUT_appmanifest_path = os.path.join(steamapps_dir, f"appmanifest_{appid}.acf")

        with open(OUT_appmanifest_path, "w") as f:
                f.write(
                        f'AppState{{"appid""{appid}""Universe""1""installdir""{steamapps_install_dir_name}""StateFlags""1026"}}'
                )
        
        if platform.system() == "Windows": os.system("explorer steam://open/downloads")
        else: os.system("steam steam://open/downloads")


def _CLI():
        if len(sys.argv) < 3:
                print("USAGE: steamapp_installer <STEAM_APPID> <STEAMAPPS_INSTALL_DIR_NAME>")
                exit(1)

        try:
                appid = int(sys.argv[1])
        except Exception as e:
                print(f"ERROR: Invalid AppID provided: {sys.argv[1]}\n" + e)
                exit(1)
        
        steamapps_install_dir_name = sys.argv[2]
	
        install(appid, steamapps_install_dir_name)

if __name__ == "__main__": _CLI()