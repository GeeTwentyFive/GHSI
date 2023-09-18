package main

import (
	"bufio"
	_ "embed"
	"fmt"
	"log"
	"os"
	"os/exec"

	"golang.org/x/sys/windows/registry"
)

//go:embed game_files.zip
var GameFilesCompressed []byte

var (
	steamLibraryDataPath string
	sourcemodsPath       string
)

func init() {

	var (
		err          error
		steamBaseDir string
	)

	steamBaseDir, err = regGetStringValueFromKey(registry.CURRENT_USER, "Software\\Valve\\Steam", "SteamPath")
	if err != nil {
		reader := bufio.NewReader(os.Stdin)

		fmt.Print("\nERROR: Failed to fetch Steam base directory path from registry.\n\nEnter path to Steam base directory (Default: \"C\\Program Files (x86)\\Steam\"): ")

		in, err := reader.ReadString('\n')
		if err != nil {
			log.Fatal("\nERROR: Failed to get user input from user\n")
		}

		if len(in) > 2 {
			if directoryExists(in) {
				steamBaseDir = in
			} else {
				log.Fatal("\nERROR: Path \"" + in + "\" does not point to an existing directory")
			}
		} else {
			steamBaseDir = "C\\Program Files (x86)\\Steam"
		}
	}

	steamLibraryDataPath = steamBaseDir + "\\steamapps\\libraryfolders.vdf"

	sourcemodsPath, err = regGetStringValueFromKey(registry.CURRENT_USER, "Software\\Valve\\Steam", "SourceModInstallPath")
	if err != nil {
		sourcemodsPath = steamBaseDir + "\\steamapps\\sourcemods"
		fmt.Println("\nERROR: Failed to fetch Sourcemod install path from directory. Using \"" + sourcemodsPath + "\" instead")
	}

}

func main() {

	installGameDependencies()

	installGame()

	MessageBox("Success!", "Installation completed!")

}

func installGameDependencies() {

	var sourceSDKBase2006Installed bool = false

	d, err := os.ReadFile(steamLibraryDataPath)
	if err != nil {
		log.Fatal("\nFailed to read from file at path \""+steamLibraryDataPath+"\"\n", err)
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
		fmt.Println("Source SDK Base 2006 not installed. Install it on Steam.\n\tLibrary -> Home -> Tools -> \"Source SDK Base 2006\"")

		cmd := exec.Command("explorer", "steam://install/215")
		cmd.Run()

		MessageBox("", "Install \"Source SDK Base 2006\" on Steam.\nPress OK after installation has completed.")
	}

}

func installGame() {

	fmt.Println("Exiting Steam (if running)...")

	cmd := exec.Command("taskkill", "/F", "/IM", "Steam.exe")
	cmd.Run()

	fmt.Print("Installing Hidden: Source - Enhanced Edition...")
	startSpinner() //Refactor

	gameFilesCompressedOutPath := os.TempDir() + "\\output.zip"

	if fileExists(gameFilesCompressedOutPath) {
		if err := os.Remove(gameFilesCompressedOutPath); err != nil {
			log.Fatal("\nFailed to remove pre-existing file at path \""+gameFilesCompressedOutPath+"\"\n", err)
		}
	}

	err := os.WriteFile(gameFilesCompressedOutPath, GameFilesCompressed, 0)
	if err != nil {
		log.Fatal("\ngame_files.zip WriteFile failed\n", err)
	}

	err = unzip(gameFilesCompressedOutPath, sourcemodsPath)
	if err != nil {
		log.Fatal("\nFailed to extract compressed game files from "+gameFilesCompressedOutPath+" to "+sourcemodsPath+"\n", err)
	}

	os.Remove(gameFilesCompressedOutPath)

	stopSpinner() //Refactor

}
