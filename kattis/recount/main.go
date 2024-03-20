package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	var m map[string]int = make(map[string]int)

	for true {
		var line, _ = reader.ReadString('\n')
		line = strings.TrimSpace(line)

		if line == "***" {
			break
		}

		var _, ok = m[line]
		if ok {
			m[line]++
		} else {
			m[line] = 1
		}
	}

	// find the most frequent word
	var max int = 0
	var maxWord string
	var maxCount int = 0
	for k, v := range m {
		if v == max {
			maxCount++
		}
		if v > max {
			max = v
			maxWord = k
			maxCount = 1
		}
	}

	if maxCount > 1 {
		fmt.Println("Runoff!")
	} else {
		fmt.Println(maxWord)
	}
}
