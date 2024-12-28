package PauseFatal

import (
	"bufio"
	"fmt"
	"os"
)

// Like log.Fatal() but waits until user inputs return character in CLI stdin before calling os.Exit()
func PauseFatal(msg string) {

	fmt.Println(msg)

	fmt.Println("Press ENTER to continue...")
	reader := bufio.NewReader(os.Stdin)
	reader.ReadString('\n')

	os.Exit(1)

}
