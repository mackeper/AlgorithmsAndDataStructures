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

	var minCarATrips, minCarBTrips = 0, 0
	var minCost = math.MaxInt
	for a := 0; a <= refrigerators; a++ {
		var b = refrigerators - a
		var carATrips = math.Ceil(float64(a) / float64(capacityCarA))
		var carBTrips = math.Ceil(float64(b) / float64(capacityCarB))
		if minCost > costCarA*int(carATrips)+costCarB*int(carBTrips) {
			minCost = costCarA*int(carATrips) + costCarB*int(carBTrips)
			minCarATrips = int(carATrips)
			minCarBTrips = int(carBTrips)
		}
	}
	fmt.Println(minCarATrips, minCarBTrips, minCost)
}
