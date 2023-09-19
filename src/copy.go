package main

import "os/exec"

func copy(src, dest string) error {

	cmd := exec.Command("xcopy", src, dest, "/E", "/Y", "/I")
	if err := cmd.Run(); err != nil {
		return err
	}

	return nil

}
