package main

import (
	"archive/zip"
	"io"
	"os"
	"path/filepath"
)

func unzip(src, dest string) error {

	r, err := zip.OpenReader(src)
	if err != nil {
		return err
	}

	defer func() {
		if err := r.Close(); err != nil {
			panic(err)
		}
	}()

	err = os.MkdirAll(dest, 0)
	if err != nil {
		return err
	}

	for _, f := range r.File {

		err := extractAndWriteFile(dest, f)
		if err != nil {
			return err
		}

	}

	return nil

}

func extractAndWriteFile(dest string, f *zip.File) error {

	outPath := filepath.Join(dest, f.Name)

	if f.FileInfo().IsDir() {

		err := os.MkdirAll(outPath, 0)
		if err != nil {
			return err
		}

	} else {

		rc, err := f.Open()
		if err != nil {
			return err
		}
		defer func() {
			if err := rc.Close(); err != nil {
				panic(err)
			}
		}()

		err = os.MkdirAll(filepath.Dir(outPath), 0)
		if err != nil {
			return err
		}

		f, err := os.OpenFile(outPath, os.O_WRONLY|os.O_CREATE|os.O_TRUNC, f.Mode())
		if err != nil {
			return err
		}
		defer func() {
			if err := f.Close(); err != nil {
				panic(err)
			}
		}()

		_, err = io.Copy(f, rc)
		if err != nil {
			return err
		}

	}

	return nil

}
