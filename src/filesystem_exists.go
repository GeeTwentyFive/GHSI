package main

import "os"

func fileExists(path string) bool {

	fileInfo, err := os.Stat(path)
	if os.IsNotExist(err) {
		return false
	}

	return !fileInfo.IsDir()

}

func directoryExists(path string) bool {

	fileInfo, err := os.Stat(path)
	if os.IsNotExist(err) {
		return false
	}

	return fileInfo.IsDir()

}
