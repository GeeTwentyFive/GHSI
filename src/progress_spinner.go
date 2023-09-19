package main

import (
	"fmt"
	"time"
)

type ProgressSpinner struct {
	quit chan bool
}

func (p *ProgressSpinner) start() {
	p.quit = make(chan bool)

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
			case <-p.quit:
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

func (p *ProgressSpinner) stop() {
	fmt.Print("\r \r")

	p.quit <- true
}
