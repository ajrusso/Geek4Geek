/*
Longest subarray with sum divisible by K

Given an array arr containing N integers and a positive integer K, find the length of the longest sub array with sum of the elements divisible by the given value K.

Example 1:

Input:
N = 6, K = 3
arr[] = {2, 7, 6, 1, 4, 5}
Output: 
4
Explanation:
The subarray is {7, 6, 1, 4} with sum 18, which is divisible by 3.
Example 2:

Input:
N = 7, K = 3
arr[] = {-2, 2, -5, 12, -11, -1, 7}
Output: 
5
Explanation:
The subarray is {2,-5,12,-11,-1} with sum -3, which is divisible by 3.
Your Task:
The input is already taken care of by the driver code. You only need to complete the function longSubarrWthSumDivByK() that takes an array arr, sizeOfArray n and a  positive integer K, and returns the length of the longest subarray which has sum divisible by K. 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 105
1 <= K <= 109
-109 <= A[i] <= 109
*/
#include <stdlib.h>
#include <stdio.h>
#include <unordered_map>
#include <algorithm>

using namespace std;

int longSubarrWthSumDivByK(int[], int, int);

int main() {
    int arr[] = {-2,2,-5,12,-11,-1,7};
    int n = 7;
    int k = 3;
    int len = 0;
    
    len = longSubarrWthSumDivByK(arr, n, k);

    printf("The longest subarray divisible by %d has a length of %d", k, len);
}

int longSubarrWthSumDivByK(int arr[], int n , int k) {
    unordered_map<int,int> map;
    int len = 0;
    int sum = 0;
    map[0] = -1;

    for(int i = 0; i < n; i++) {
        sum += arr[i];
        int rem = sum % k;
        
        if(rem < 0) {
            rem += k;
        }
        
        if(map.find(rem) == map.end()) {
            map[rem] = i;
        } else {
             len = max(len, i - map[rem]);
        }
    }

    return len;
}