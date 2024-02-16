/*
Number of subarrays with maximum values in given range

Given an array of N elements and L and R, print the number of sub-arrays such that the value of the maximum array element in that subarray is at least L and at most R.

Example 1:

Input : 
Arr = {2, 0, 11, 3, 0}
L = 1 and R = 10
Output : 
4
Explanation:
The sub-arrays {2}, {2, 0}, {3} and {3, 0} have maximum in range 1-10.
Example 2:

Input : 
Arr = {3, 4, 1}
L = 2 and R = 4
Output : 
5
Explanation:
The sub-arrays {3}, {3, 4}, {3,4,1}, {4} and {4, 1} have maximum in range 2-4.
Your Task:
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function countSubarrays() that takes an array arr, sizeOfArray (n), element L, integer R, and return the number of subarray with the maximum in range L-R. The driver code takes care of the printing.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ N ≤ 105
1 ≤ arr[i] ≤ 109
1 ≤ L ≤ R ≤ 109
*/

#include <stdlib.h>
#include <stdio.h>

using namespace std;

long countSubarrays(int[], int, int, int);

int main(){
    int a[] = {3,4,1};
    int n = sizeof(a) / sizeof(a[0]);
    int L = 2;
    int R = 4;
    long result;

    result = countSubarrays(a, n, L, R);

    printf("%d sub-arrays have a maximun in range %d-%d", result
                                                        , L
                                                        , R);
}

long countSubarrays(int a[], int n, int L, int R) {
    long count = 0;
    int consecutive = 0;
    int max = 0;
    int dt = 0;
    for(int i = 0; i < n; i++) {
        consecutive++;
        if(a[i] <= R) {
            if(a[i] > max)
                max = a[i];

            if(a[i] >= L && a[i] <= R)
                dt = 0;
            else
                dt++;

            if(max >= L && max <= R)
                count += consecutive - dt;

        } else {
            consecutive = 0;
            max = 0;
            dt = 0;
        }
    }
    return count;
}