package main

import (
	"bufio"
	"fmt"
	"os"
	// "strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	var bottles int
	fmt.Fscanf(reader, "%d\n", &bottles)

	var aliceTime, deltaAlice int
	fmt.Fscanf(reader, "%d %d\n", &aliceTime, &deltaAlice)

	var bobTime, deltaBob int
	fmt.Fscanf(reader, "%d %d\n", &bobTime, &deltaBob)

	aliceChuggingTime := chuggingTime(aliceTime, deltaAlice, bottles)
	bobChuggingTime := chuggingTime(bobTime, deltaBob, bottles)

	if aliceChuggingTime < bobChuggingTime {
		fmt.Println("Alice")
	} else if aliceChuggingTime > bobChuggingTime {
		fmt.Println("Bob")
	} else {
		fmt.Println("=")
	}
}

func chuggingTime(time, delta, bottles int) int {
	var chuggingTime = 0
	for i := 0; i < bottles; i++ {
		chuggingTime += time + (i * delta)
	}
	return chuggingTime
}
