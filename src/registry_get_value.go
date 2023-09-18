package main

import (
	"golang.org/x/sys/windows/registry"
)

func regGetStringValueFromKey(baseKey registry.Key, path, name string) (string, error) {

	k, err := registry.OpenKey(baseKey, path, registry.QUERY_VALUE)
	if err != nil {
		return "", err
	}
	defer k.Close()

	s, _, err := k.GetStringValue(name)
	if err != nil {
		return "", err
	}

	return s, nil

}
