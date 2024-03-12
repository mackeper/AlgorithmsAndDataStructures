package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	// "strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	var costCarA, capacityCarA, costCarB, capacityCarB, refrigerators int
	fmt.Fscanf(reader, "%d %d %d %d %d\n", &costCarA, &capacityCarA, &costCarB, &capacityCarB, &refrigerators)

    // dictinary
    var  

	var minCost = math.MaxInt
	for a := 0; a < refrigerators; a++ {
        var carATrips = 
		var b = refrigerators - a
		minCost = min(minCost, costCarA*a+costCarB*b)
	}
	fmt.Println(minCost)
}
