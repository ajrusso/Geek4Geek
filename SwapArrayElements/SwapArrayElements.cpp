/*
Swap the Array Elements

Given an array arr of n positive integers. The task is to swap every ith element of the array with (i+2)th element.

Example 1:

Input:
n = 3
arr[] = 1 2 3
Output:
3 2 1
Explanation:
Swapping 1 and 3, makes the array 3 2 1. There is only one swap possible in this array.
Example 2:

Input:
n = 5
arr[] = 1 2 3 4 5
Output:
3 4 5 2 1
Explanation:
Swapping 1 and 3, makes the array 3 2 1 4 5.
Now, swapping 2 and 4, makes the array 3 4 1 2 5. 
Again,swapping 1 and 5, makes the array 3 4 5 2 1.
Your Task:
Your task is to complete the function swapElements(), which should swap each ith element with (i+2)th element.

Expected Time Complexity: O(n)
Expected Auxilary Space: O(1)

Constraints:
1 <= n <= 106
0 <= arri <= 109
*/

#include <stdlib.h>
#include <stdio.h>

using namespace std;

void swapElements(int[], int);

int main() {
    int n = 2;
    int arr[] = {1,2};

    swapElements(arr, n);
    for(int i : arr)
        printf("%d ", i);
}

void swapElements(int arr[], int n) {
    int temp;
    for(int i = 0; i < n - 2; i++) {
        temp = arr[i + 2];
        arr[i + 2] = arr[i];
        arr[i] = temp;
    }
}