package main

import (
	_ "embed"
	"fmt"
	"os"
	"os/exec"

	"golang.org/x/sys/windows/registry"

	"GHSI/components/FilesystemUtils"
	"GHSI/components/PauseFatal"
	"GHSI/components/Win32Utils"
)

//go:embed game_files.tar.gz
var gameFilesCompressedData []byte

func main() {

	var err error
	var cmd *exec.Cmd

	// Install Source SDK Base 2006:

	cmd = exec.Command("explorer", "steam://install/215")
	cmd.Run()

	Win32Utils.MessageBox("", "Install \"Source SDK Base 2006\" on Steam")

	// Install Hidden: Source - Enhanced Edition:

	fmt.Println("Installing Hidden: Source - Enhanced Edition...")

	gameFilesOutPath := os.TempDir() + "\\game_files.tar.gz"

	if FilesystemUtils.FileExists(gameFilesOutPath) {
		err = os.Remove(gameFilesOutPath)
		if err != nil {
			PauseFatal.PauseFatal("ERROR: Failed to remove file \"" + gameFilesOutPath + "\"")
		}
	}

	err = os.WriteFile(gameFilesOutPath, gameFilesCompressedData, 0)
	if err != nil {
		PauseFatal.PauseFatal("ERROR: Failed to write Hidden: Source - Enhanced Edition compressed data to \"" + os.TempDir() + "\"")
	}

	var sourcemodsPath string

	sourcemodsPath, err = Win32Utils.Registry_GetStringValueFromKey(registry.CURRENT_USER, "Software\\Valve\\Steam", "SourceModInstallPath")
	if err != nil {
		PauseFatal.PauseFatal("ERROR: Failed to fetch Sourcemod install path from registry")
	}

	err = os.Chdir(sourcemodsPath)
	if err != nil {
		PauseFatal.PauseFatal("ERROR: Failed to change current working directory to \"" + sourcemodsPath + "\"")
	}

	cmd = exec.Command("tar", "-xf", gameFilesOutPath)
	if err = cmd.Run(); err != nil {
		PauseFatal.PauseFatal("ERROR: Failed to extract Hidden: Source - Enhanced Edition to \"" + sourcemodsPath + "\"")
	}

	os.Remove(gameFilesOutPath)

	Win32Utils.MessageBox("Success!", "Restart Steam to complete installation")

}
