GHSInstaller (Gee's Hidden: Source Installer) is a program which installs a modified version of Hidden: Source and a [launcher](https://github.com/GeeTwentyFive/GHSLauncher)

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
- Automatic (attempted) port forwarding (27015)
- Borderless window fix for alt-tabbing
- Shotgun damage nerf (17x9 -> 11x9)
- Increased FN303 (best weapon) clip size (15 -> 20)
- Increased sonic trip alarm count (1 -> 4)
- Removed broken maps which crash game
- Unofficial community Discord link in MOTD
- Dedicated server plugins: RTV, nominations, mapchooser, phys crash fix, pigshove, +visible, black hidden checker, BSOD fix, weight reporter, autobot


# Usage
Run `GHSInstaller.exe` -> after install: Launch with `GHSLauncher.exe` on Desktop

For dedicated server: Download `HiddenServer.7z` -> extract -> run `GHSServerLauncher.exe` ([source](https://github.com/GeeTwentyFive/GHSServerLauncher))


# Gamma's Dedicated Server Setup & Quick Start Guide

- Download "HiddenServer.7z" from the releases page. Because it comes in a compressed archive, you will need 7-Zip or WinRAR to extract it.

- Create a new folder for the server. This folder can be put anywhere and named what you like.
  Once the folder is made, extract the files inside "HiddenServer.7z" to your new folder.

- Before you launch the server straight away, you should look at the server config.
  Find "server.cfg", at ServerFiles > hidden > cfg.
  The config comes with most cvars you'd need with explanations, including all of the Hidden-specific ones.
  Edit them to your liking, or leave it as it is.

- You can also check the Sourcemod plugins at ServerFiles > hidden > addons > sourcemod > plugins.
  For example, if you want Pigshove to be enabled, move "hsm_pigshove" from the "disabled" folder into "plugins".
  You can find most Hidden plugins here - https://www.sourcemod.net/plugins.php?cat=0&mod=15&title=&author=&description=&search=1
  Take note that some plugins have their own cvars you can add to the server config.

- To start the server up and play, open GHSServerLauncher. It'll give you the usual SRCDS user interface.
  Don't bother with changing the server name or password in the GUI; the server config will overwrite it.
  Remember to change the RCON Password while you're there.

- If, for some reason, the GUI crashes upon starting the server, use "RUN_AS_CONSOLE".
  This will give you a simple console to run the server from.
  If you want to adjust starting maps, you can edit the batch file in a text editor.
  The following is some useful arguments to know.
```
  -nomaster: Hides your server from the browser.
  -maxplayers <1 - 10>: Changes player limit. While 10 is the limit, only 9 people can actually play at once.
  -insecure: Disables Valve Anti-Cheat (VAC).
```
  You can also apply arguments to the GUI by copy-pasting the batch file and removing "-console".


# Contributors
- Gamma (shygamma)


### Unofficial community Discord server: https://discord.gg/8fvmPxjfaF