# Problems

#### Counting inversions (Fenwick tree)
Inversion Count for an array indicates – how far (or close) the array is from being sorted.   
Sorted array: inversion count is 0.  
reverse order: inversion count is the maximum.   
Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j  
Ex:  
a = 7 6 1 2 3 4 5 6  
(a[0], a[1]) is on inversion

With fenwick: O(n log n)

https://www.geeksforgeeks.org/counting-inversions/

#### Find kth tallest (Fenwick tree)
Given an array and a number k where k is smaller than size of array, we need to find the k’th smallest element in the given array. It is given the quantity of each element.

With fenwick: O(log^2 n)

##### Find kth tallest (Distinct elements)
Given an array and a number k where k is smaller than size of array, we need to find the k’th smallest element in the given array. It is given that ll array elements are distinct.

Simple solution: sort and return element k-1.

https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/
