#include <iostream>
#include <stack>
#include <queue>
using namespace std;
//following array  4  15  8  3  28  21. whtas is array after ssecond pass of selection sort
//3 4 8 15 21 28
//selection sort continues until n-1 of the n items in array have been swapped
//Quicksoret is O(n2) in teh worst case
//In worst case, insertion sort comparison occurs n*(n-1)/2 times
//MergeSort is O(n*log2n) in worst case time
//in worst case, binary search is O(log2n)
//Bubble sort compares adjacent items and swaps them if they are out of order
//Bubble sort, Selection sort, Insertion sort are all O(n2)