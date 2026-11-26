GHSInstaller (Gee's Hidden: Source Installer) is a program which installs a modified version of Hidden: Source (and a [launcher](https://github.com/GeeTwentyFive/GHSLauncher) for Windows) for Windows / Linux+Proton

The modifications:
- Game not launching fix
- Optimized graphical settings for seeing the Hidden
- Optimized network settings for responsiveness, consistency, physkilling, and other tricks involving props
- Includes many community maps
- cl_downloadfilter all (to (usually) prevent missing map error when joining a server which is running a map you don't have)
- Listen server fix
- Sonic trip alarm sound fix
- Master server list fix
- Fixed worse recoil with higher ping
- Borderless window fix for alt-tabbing
- Shotgun damage nerf (17x9 -> 11x9)
- Increased FN303 (best weapon) clip size (15 -> 20)
- Increased sonic trip alarm count (1 -> 4)
- Removed broken maps which crash game
- Unofficial community Discord link in MOTD
- Dedicated server plugins: RTV, nominations, mapchooser, phys crash fix, pigshove, +visible, black hidden checker, BSOD fix, weight reporter, autobot
- Various bug fixes


# Usage

Run `GHSInstaller`

For dedicated server: Download `HiddenServer.zip` -> extract -> run `RUN.bat`

(if stuff is brokey, see [Troubleshooting](#troubleshooting) section below)


# Gamma's Dedicated Server Setup & Quick Start Guide

- Download "HiddenServer.zip" from the releases page.

- Create a new folder for the server. This folder can be put anywhere and named what you like.
  Once the folder is made, extract the files inside "HiddenServer.zip" to your new folder.

- Before you launch the server straight away, you should look at the server config.
  Find "server.cfg", at ServerFiles > hidden > cfg.
  The config comes with most cvars you'd need with explanations, including all of the Hidden-specific ones.
  Edit them to your liking, or leave it as it is.

- You can also check the Sourcemod plugins at ServerFiles > hidden > addons > sourcemod > plugins.
  For example, if you want Pigshove to be enabled, move "hsm_pigshove" from the "disabled" folder into "plugins".
  You can find most Hidden plugins here - https://www.sourcemod.net/plugins.php?cat=0&mod=15&title=&author=&description=&search=1
  Take note that some plugins have their own cvars you can add to the server config.

- To start the server up and play, run `RUN.bat`. It'll give you the usual SRCDS user interface.
  Don't bother with changing the server name or password in the GUI; the server config will overwrite it.
  Remember to change the RCON Password while you're there.

- If, for some reason, the GUI crashes upon starting the server, use `RUN_AS_CONSOLE.bat`.
  This will give you a simple console to run the server from.
  If you want to adjust starting maps, you can edit the batch file in a text editor.
  The following is some useful arguments to know.
```
  -nomaster: Hides your server from the browser.
  -maxplayers <1 - 10>: Changes player limit. While 10 is the limit, only 9 people can actually play at once.
  -insecure: Disables Valve Anti-Cheat (VAC).
```
  You can also apply arguments to the GUI by copy-pasting the batch file and removing "-console".


# Troubleshooting

- Installer no workie
  - See [Manual install](#manual-install) section below

- Crash during loading screen
  - Make sure you have a default audio playback device selected in Windows settings


# Manual install

1) Install `Source SDK Base 2006` on Steam
2) Download/clone repo (On GitHub: Green `Code` button -> `Download ZIP`)
3) Move *contents* of `embed/SourceSDKBase2006_Patches/` to `<STEAM_INSTALL_DIR>/steamapps/common/Source SDK Base/`
4) Move *contents* of `embed/GameFiles/` to `<STEAM_INSTALL_DIR>/steamapps/sourcemods/`
5) If on Windows: Copy `embed/GHSLauncher.exe` to Desktop (use this to launch game on Windows (has Windows-specific fixes))
6) Restart Steam


# Contributors

- Gamma (shygamma)


### Unofficial community Discord server: https://discord.gg/8fvmPxjfaF