package FilesystemUtils

import "os"

func FileExists(path string) bool {

	fileInfo, err := os.Stat(path)
	if os.IsNotExist(err) {
		return false
	}

	return !fileInfo.IsDir()

}

func DirectoryExists(path string) bool {

	fileInfo, err := os.Stat(path)
	if os.IsNotExist(err) {
		return false
	}

	return fileInfo.IsDir()

}
