package main

import (
	"bufio"
	"fmt"
	"os"
	"os/exec"

	"golang.org/x/sys/windows/registry"
)

var (
	installerDataPath = os.TempDir() + "\\GHSI"

	steamBaseDir         string
	steamLibraryDataPath string
	appManifest          []byte
	sourcemodsPath       string

	progressSpinner ProgressSpinner
)

func init() {

	var err error

	if !fileExists("InstallerData") {
		pauseFatal("ERROR: InstallerData not found")
	}

	fmt.Print("Extracting installer data...")
	progressSpinner.start()

	err = unzip("InstallerData", os.TempDir())
	if err != nil {
		pauseFatal("ERROR: Failed to extract installer data")
	}

	progressSpinner.stop()

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
		fmt.Println("\nERROR: Failed to fetch Sourcemod install path from directory. Using \"" + sourcemodsPath + "\" instead")
	}

}

func main() {

	fmt.Println("Exiting Steam (if running)...")

	cmd := exec.Command("taskkill", "/F", "/IM", "Steam.exe")
	cmd.Run()

	installGameDependencies()

	installGame()

	os.RemoveAll(installerDataPath)

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

		steamappsPath := steamBaseDir + "\\steamapps"
		steamappsCommonPath := steamappsPath + "\\common"

		var err error

		err = os.WriteFile(steamappsPath+"\\appmanifest_215.acf", appManifest, 0)
		if err != nil {
			pauseFatal("App manifest 215 WriteFile() failed")
		}

		err = copy(installerDataPath+"\\source_sdk_base_2006", steamappsCommonPath)
		if err != nil {
			pauseFatal("ERROR: Failed to copy Source SDK Base 2006 files from \"" + installerDataPath + "\" to \"" + steamappsCommonPath + "\"")
		}

		progressSpinner.stop()
	}

}

func installGame() {

	fmt.Print("Installing Hidden: Source - Enhanced Edition...")
	progressSpinner.start()

	err := copy(installerDataPath+"\\game_files", sourcemodsPath)
	if err != nil {
		pauseFatal("ERROR: Failed to copy Hidden: Source - Enhanced Edition files from \"" + installerDataPath + "\" to \"" + sourcemodsPath + "\"")
	}

	progressSpinner.stop()

}
