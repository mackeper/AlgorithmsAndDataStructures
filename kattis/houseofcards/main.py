#! /usr/bin/python3

import sys
 
h = int(input())
cards = 0
for i in range(1, h):
    cards += i*2+i
cards += h*2

while cards % 4 != 0:
    cards += h
    h += 1
    cards += h*2
    #print(cards)

print(h)
