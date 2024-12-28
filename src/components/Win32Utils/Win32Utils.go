package Win32Utils

import (
	"syscall"
	"unsafe"

	"golang.org/x/sys/windows/registry"
)

var (
	user32         = syscall.NewLazyDLL("user32.dll")
	messageBoxProc = user32.NewProc("MessageBoxW")
)

func MessageBox(caption, text string) {

	messageBoxProc.Call(
		0,
		uintptr(unsafe.Pointer(syscall.StringToUTF16Ptr(text))),
		uintptr(unsafe.Pointer(syscall.StringToUTF16Ptr(caption))),
		0x00040000, //MB_TOPMOST
	)

}

func Registry_GetStringValueFromKey(baseKey registry.Key, path, name string) (string, error) {

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
