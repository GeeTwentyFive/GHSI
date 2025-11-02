import ctypes
import winreg
import os
import tempfile
import base64
import tarfile


GAME_FILES_COMPRESSED_DATA = b"" # TODO
SERVER_BROWSER_FIX_COMPRESSED_DATA = b"" # TODO


def show_message_box(msg: str, title: str = ""):
	ctypes.windll.user32.MessageBoxW(0, msg, title, 0)

def registry_get_string_from_key(root: winreg.HKEYType, path: str, name: str):
	value = winreg.QueryValueEx(
		winreg.OpenKey(root, path),
		name
	)
	if value[1] != winreg.REG_SZ:
		raise Exception(f"ERROR: Value of key {name} at path {path} is not string (REG_SZ)")
	return value[0]


# Prompt user to install Source SDK Base 2006
os.system("explorer steam://install/215")
show_message_box("Install 'Source SDK Base 2006' on Steam\n\nPRESS 'OK' ONLY *AFTER* IT IS ALREADY INSTALLED")


# Install Hidden: Source - Enhanced Edition

print("Installing Hidden: Source - Enhanced Edition...")

try:
	game_files_out_path = tempfile.gettempdir() + "\\_GHSI_game_files.tar.gz"
	with open(game_files_out_path, "wb") as f:
		f.write(base64.a85decode(GAME_FILES_COMPRESSED_DATA))
except Exception as e:
	input(f"ERROR: Failed to write Hidden: Source - Enhanced Edition compressed data to {game_files_out_path}\n{e}")
	exit(1)

try:
	sourcemods_path = registry_get_string_from_key(winreg.HKEY_CURRENT_USER, "Software\\Valve\\Steam", "SourceModInstallPath")
except Exception as e:
	input(f"ERROR: Failed to fetch Sourcemod install path from registry\n{e}")
	exit(1)

try:
	with tarfile.open(game_files_out_path, "r:gz") as t:
		t.extractall(sourcemods_path)
except Exception as e:
	input(f"ERROR: Failed to extract Hidden: Source - Enhanced Edition to {sourcemods_path}\n{e}")
	exit(1)


# Patch Source SDK Base 2006 server browser

print("Patching Source SDK Base 2006 server browser...")

try:
	server_browser_fix_out_path = tempfile.gettempdir() + "\\_GHSI_server_browser_fix.tar.gz"
	with open(server_browser_fix_out_path, "wb") as f:
		f.write(base64.a85decode(GAME_FILES_COMPRESSED_DATA))
except Exception as e:
	input(f"ERROR: Failed to write server browser fix compressed data to {server_browser_fix_out_path}\n{e}")
	exit(1)

try:
	steam_path = registry_get_string_from_key(winreg.HKEY_CURRENT_USER, "Software\\Valve\\Steam", "SteamPath")
except Exception as e:
	input(f"ERROR: Failed to fetch Steam path from registry\n{e}")
	exit(1)
source_sdk_base_2006_path = steam_path + "steamapps\\common\\Source SDK Base"

try:
	with tarfile.open(server_browser_fix_out_path, "r:gz") as t:
		t.extractall(source_sdk_base_2006_path)
except Exception as e:
	input(f"ERROR: Failed to extract server browser fix to {source_sdk_base_2006_path}\n{e}")
	exit(1)


try: os.remove(game_files_out_path)
except: pass
try: os.remove(server_browser_fix_out_path)
except: pass

show_message_box("Restart Steam to complete installation", "Success!")