package main

import (
	"syscall"
	"unsafe"
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
