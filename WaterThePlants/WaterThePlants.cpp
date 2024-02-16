/*
Water The Plants

A gallery with plants is divided into n parts, numbered 0, 1, 2, 3, ..., n-1. There are provisions for attaching water sprinklers in every division. A sprinkler with range x at division i can water all divisions from i-x to i+x.

Given an array gallery[] consisting of n integers, where gallery[i] is the range of the sprinkler at partition i (a power of -1 indicates no sprinkler attached), return the minimum number of sprinklers that need to be turned on to water the entire gallery. If there is no possible way to water the full length using the given sprinklers, print -1.

Example 1:

Input:
n = 6
gallery[] = {-1, 2, 2, -1, 0, 0}
Output:
2
Explanation: 
Sprinklers at index 2 and 5
can water the full gallery, span of
sprinkler at index 2 = [0,4] and span
of sprinkler at index 5 = [5,5].
Example 2:

Input:
n = 9
gallery[ ] = {2, 3, 4, -1, 2, 0, 0, -1, 0}
Output:
-1
Explanation: 
No sprinkler can throw water
at index 7. Hence all plants cannot be
watered.
Example 3:

Input:
n = 9
gallery[ ] = {2, 3, 4, -1, 0, 0, 0, 0, 0}
Output:
3
Explanation: 
Sprinkler at indexes 2, 7 and
8 together can water all plants.
Your task:
You do not have to take any input or print anything. Your task is to complete the function min_sprinklers() which takes the array gallery[ ] and the integer n as input parameters and returns the minimum number of sprinklers that need to be turned on to water the entire gallery.

Expected Time Complexity: O( nlog(n) )
Expected Auxiliary Space: O( n )

Constraints:
1 ≤ n ≤ 105
gallery[i] ≤ 50
*/
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

int min_sprinklers(int[], int);

int main() {
    int gallery[] = {1,0,4,2,0,6,2,4};
    int n = 8;

    int result = min_sprinklers(gallery, n);
    
    if(result == -1)
        printf("It is not possible to water the plants with the given sprinklers");
    else
        printf("%d sprinklers can water all the divisions", result);
}

int min_sprinklers(int gallery[], int n) {
    int count = 0;
    vector<int> coverage(n, -1);

    // Iterate through the gallery for sprinkler coverages
    for(int i = 0; i < n; i++) {
        
        // Handle no sprinkler in the given division
        if(gallery[i] == -1)
            continue;        

        int left = max( 0, i - gallery[i]);
        int right = min(n - 1, i + gallery[i]);
        
        // Store the index of the sprinkler  with the largest range in the coverage[]
        for(int j = left; j <= right; j++) {
            coverage[j] = max(coverage[j], right);
        }
    }

    // Count Sprinklers required to cover the entire gallery
    int cur = 0;
    int next = 0;

    while(cur < n) {
        if(coverage[cur] == -1)
            return -1;
        
        ++count;
        next = coverage[cur] + 1;
        
        if(next >= n)
            break;
            
        cur = next;
    }

    return count;
}