/*
Transform To Prime

Given an array of n integers. Find the minimum positive number to be inserted in array, so that sum of all elements of array becomes prime.

Example 1:

Input:
N=5
arr = {2, 4, 6, 8, 12}
Output:  
5
Explanation: 
The sum of the array is 32 ,we can add 5 to this to make it 37 which is a prime number.
Example 2:

Input:
N=3
arr = {1, 5, 7}
Output:  
0 
Explanation: 
The sum of the array is 13 which is already prime. 
Your Task:
You don't need to read input or print anything. Your task is to complete the function minNumber() that takes array arr and integer N as input parameters and returns the minimum positive number to be inserted in the array so as to make it's sum a prime number.

Expected Time Complexity: O(N log(log N))
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ N ≤ 105
1 ≤ sum of all elements ≤ 106
*/

#include <stdlib.h>
#include <stdio.h>

using namespace std;

int minNumber(int[], int);
int sumOfArray(int[], int);

int main() {
    int arr[] = {2,4,6,8,12};
    int N = sizeof(arr) / sizeof(int);
    int result;

    result = minNumber(arr, N);

    if(result)
        printf("The sum of the array is %d, we ", sumOfArray(arr, N));
    else
        printf("The sum of the array is %d, which is already prime", sumOfArray(arr, N));
}

int minNumber(int arr[], int N) {
    int result = 0;
    int sum = 0;

    // Sum array
    sum = sumOfArray(arr, N);
    // Is sum prime?
    // If not, what is the min pos # to add to array to make the sum prime

    return result;
}

int sumOfArray(int arr[], int N) {
    int count = 0;
    
    for(int i = 0; i < N; i++) {
        count += arr[i];
    }
    
    return count;
}