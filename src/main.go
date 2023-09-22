package main

import (
	"bufio"
	_ "embed"
	"fmt"
	"os"
	"os/exec"

	"golang.org/x/sys/windows/registry"
)

//go:embed 7zdec.exe
var szDecData []byte

//go:embed source_sdk_base_2006.7z
var sourceSdkBase2006CompressedData []byte

//go:embed game_files.7z
var gameFilesCompressedData []byte

var (
	steamBaseDir         string
	steamLibraryDataPath string
	appManifest          []byte
	sourcemodsPath       string

	szDecPath string = os.TempDir() + "\\7zdec.exe"

	progressSpinner ProgressSpinner
)

func init() {

	var err error

	steamBaseDir, err = regGetStringValueFromKey(registry.CURRENT_USER, "Software\\Valve\\Steam", "SteamPath")
	if err != nil {
		reader := bufio.NewReader(os.Stdin)

		fmt.Print("\nERROR: Failed to fetch Steam base directory path from registry.\n\nEnter path to Steam base directory (Default: \"C\\Program Files (x86)\\Steam\"): ")

		in, err := reader.ReadString('\n')
		if err != nil {
			pauseFatal("ERROR: Failed to get user input from user")
		}

		if len(in) > 2 {
			if directoryExists(in) {
				steamBaseDir = in
			} else {
				pauseFatal("ERROR: Path \"" + in + "\" does not point to an existing directory")
			}
		} else {
			steamBaseDir = "C\\Program Files (x86)\\Steam"
		}
	}

	//Using "libraryfolders.vdf" to check whether or not Source SDK Base 2006 is installed instead of "appmanifest_215.vdf"
	//cause multiple Steam library installation locations are supported by Steam,
	//and the contents of each are updated to "libraryfolders.vdf".
	//It is a library install location -independent resource regarding the installed apps in all the registered install locations for the Steam library.
	//Using it instead of checking each location.
	steamLibraryDataPath = steamBaseDir + "\\steamapps\\libraryfolders.vdf"

	appManifest = []byte(appManifestPrePath + steamBaseDir + "\\steam.exe" + appManifestPostPath)

	sourcemodsPath, err = regGetStringValueFromKey(registry.CURRENT_USER, "Software\\Valve\\Steam", "SourceModInstallPath")
	if err != nil {
		sourcemodsPath = steamBaseDir + "\\steamapps\\sourcemods"
		fmt.Println("\nERROR: Failed to fetch Sourcemod install path from registry. Using \"" + sourcemodsPath + "\" instead")
	}

	if fileExists(szDecPath) {
		err = os.Remove(szDecPath)
		if err != nil {
			pauseFatal("ERROR: Failed to remove 7zdec.exe at \"" + os.TempDir() + "\"")
		}
	}

	err = os.WriteFile(szDecPath, szDecData, 0)
	if err != nil {
		pauseFatal("ERROR: Failed to extract 7zdec.exe")
	}

}

func main() {

	fmt.Println("Exiting Steam (if running)...")

	cmd := exec.Command("taskkill", "/F", "/IM", "Steam.exe")
	cmd.Run()

	installGameDependencies()

	installGame()

	os.Remove(szDecPath)

	MessageBox("Success!", "Installation completed!")

}

func installGameDependencies() {

	var sourceSDKBase2006Installed bool = false

	d, err := os.ReadFile(steamLibraryDataPath)
	if err != nil {
		pauseFatal("Failed to read from file at path \"" + steamLibraryDataPath + "\"")
	}

	// Source SDK Base 2006 AppID byte pattern in "libraryfolders.vdf" is "34, 50, 49, 53, 34"
	for i := 0; i < len(d)-5; i++ {
		if d[i] == 34 && d[i+1] == 50 && d[i+2] == 49 && d[i+3] == 53 && d[i+4] == 34 { //Written like this for readability; Instead of doing two nested for-loops
			sourceSDKBase2006Installed = true
			break
		}
	}

	if sourceSDKBase2006Installed {
		fmt.Println("Source SDK Base 2006 already installed")
	} else {
		fmt.Print("Installing Source SDK Base 2006...")
		progressSpinner.start()

		manifestPath := steamBaseDir + "\\steamapps\\appmanifest_215.acf"
		steamappsCommonPath := steamBaseDir + "\\steamapps\\common"

		var err error

		if fileExists(manifestPath) { // If the manifest exists but the Source SDK Base 2006 AppID isn't in "libraryfolders.vdf", then Source SDK Base 2006 install might be brokey, so this might (along with following code) fix it :thumbsup:
			err = os.Remove(manifestPath)
			if err != nil {
				pauseFatal("ERROR: Failed to remove file \"" + manifestPath + "\"")
			}
		}

		err = os.WriteFile(manifestPath, appManifest, 0)
		if err != nil {
			pauseFatal("App manifest 215 WriteFile() failed")
		}

		sSDKBase2006CDOutPath := os.TempDir() + "\\source_sdk_base_2006.7z"

		if fileExists(sSDKBase2006CDOutPath) {
			err = os.Remove(sSDKBase2006CDOutPath)
			if err != nil {
				pauseFatal("ERROR: Failed to remove file \"" + sSDKBase2006CDOutPath + "\"")
			}
		}

		err = os.WriteFile(sSDKBase2006CDOutPath, sourceSdkBase2006CompressedData, 0)
		if err != nil {
			pauseFatal("ERROR: Failed to write Source SDK Base 2006 compressed data to \"" + os.TempDir() + "\"")
		}

		err = os.Chdir(steamappsCommonPath)
		if err != nil {
			pauseFatal("ERROR: Failed to change current working directory to \"" + steamappsCommonPath + "\"")
		}

		cmd := exec.Command(szDecPath, "x", sSDKBase2006CDOutPath)
		if err = cmd.Run(); err != nil {
			pauseFatal("ERROR: Failed to extract Source SDK Base 2006 to \"" + steamappsCommonPath + "\"")
		}

		os.Remove(sSDKBase2006CDOutPath)

		progressSpinner.stop()
	}

}

func installGame() {

	fmt.Print("Installing Hidden: Source - Enhanced Edition...")
	progressSpinner.start()

	var err error

	gameFilesCDOutPath := os.TempDir() + "\\game_files.7z"

	if fileExists(gameFilesCDOutPath) {
		err = os.Remove(gameFilesCDOutPath)
		if err != nil {
			pauseFatal("ERROR: Failed to remove file \"" + gameFilesCDOutPath + "\"")
		}
	}

	err = os.WriteFile(gameFilesCDOutPath, gameFilesCompressedData, 0)
	if err != nil {
		pauseFatal("ERROR: Failed to write Hidden: Source - Enhanced Edition compressed data to \"" + os.TempDir() + "\"")
	}

	err = os.Chdir(sourcemodsPath)
	if err != nil {
		pauseFatal("ERROR: Failed to change current working directory to \"" + sourcemodsPath + "\"")
	}

	cmd := exec.Command(szDecPath, "x", gameFilesCDOutPath)
	if err = cmd.Run(); err != nil {
		pauseFatal("ERROR: Failed to extract Hidden: Source - Enhanced Edition to \"" + sourcemodsPath + "\"")
	}

	os.Remove(gameFilesCDOutPath)

	progressSpinner.stop()

}
