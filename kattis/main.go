package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	var n, k int
	fmt.Fscanf(reader, "%d %d\n", &n, &k)

	numbers, _ := reader.ReadString('\n')
	numbersList := strings.Fields(numbers)

	printEveryKth(numbersList, k)
}

func printEveryKth(numbersList []string, kInt int) {
	for i, num := range numbersList {
		if (i+1)%kInt == 0 {
			fmt.Print(num, " ")
		}
	}
}
