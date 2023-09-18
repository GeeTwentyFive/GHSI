package main

import (
	"fmt"
	"time"
)

// TO DO?: Make it duck-typed
// ps = ProgressSwirl()
// ps.stop()

// REFACTOR THIS!!!

var quit chan bool

func startSpinner() {
	quit = make(chan bool)

	go func() {
		var (
			spinSymbols  = "|/-\\"
			spinInterval = 200 * time.Millisecond

			selectedSymbolIndex = 0
			timeSinceLastSpin   = time.Now()
		)

		fmt.Println()

		for {
			select {
			case <-quit:
				return

			default:
				if time.Now().Compare(timeSinceLastSpin.Add(spinInterval)) == 1 {
					fmt.Print("\r" + string(spinSymbols[selectedSymbolIndex]))

					timeSinceLastSpin = time.Now()

					if selectedSymbolIndex < 3 {
						selectedSymbolIndex++
					} else {
						selectedSymbolIndex = 0
					}
				}
			}
		}
	}()
}

func stopSpinner() {
	fmt.Print("\r \r")

	quit <- true
}
