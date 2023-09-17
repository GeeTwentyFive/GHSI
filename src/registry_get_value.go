package main

import (
	"log"

	"golang.org/x/sys/windows/registry"
)

func regGetStringValueFromKey(k registry.Key, path, name string) string {

	_k, err := registry.OpenKey(k, path, registry.QUERY_VALUE)
	if err != nil {
		log.Fatal("\nFailed to get handle to key at path \""+path+"\"\n", err)
		return ""
	}
	defer _k.Close()

	s, _, err := _k.GetStringValue(name)
	if err != nil {
		log.Fatal("\nFailed to read string value from \""+name+"\" in key \""+path+"\"\n", err)
		return ""
	}

	return s

}
