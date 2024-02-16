/*
All Unique Permutations of an Array

Given an array arr[] of length n. Find all possible unique permutations of the array in sorted order. A sequence A is greater than sequence B if there is an index i for which Aj = Bj for all j<i and Ai > Bi.

Example 1:

Input: 
n = 3
arr[] = {1, 2, 1}
Output: 
1 1 2
1 2 1
2 1 1
Explanation:
These are the only possible unique permutations
for the given array.
Example 2:

Input: 
n = 2
arr[] = {4, 5}
Output: 
Only possible 2 unique permutations are
4 5
5 4
Your Task:
You don't need to read input or print anything. You only need to complete the function uniquePerms() that takes an integer n, and an array arr of size n as input and returns a sorted list of lists containing all unique permutations of the array.

Expected Time Complexity:  O(n*n!)
Expected Auxilliary Space: O(n*n!)

Constraints:
1 ≤ n ≤ 9
1 ≤ arri ≤ 10
*/

#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> uniquePerms(vector<int>&, int);
vector<vector<int>> find_permutations(vector<int>, int, int);
int factorial(int);

int main() {
    int n = 3;
    vector<int> arr = {1,2,1};

    vector<vector<int>> result = uniquePerms(arr, n);

    for(auto perm : result) {
        for(auto digit : perm)
            printf("%d ", digit);
        printf("\n");
    }
}

vector<vector<int>> uniquePerms(vector<int> &arr, int n) {
    vector<vector<int>> perms = {};

    // Find all other permutations 
    perms = find_permutations(arr, n, 0);

    // Erase non-unique perms
    sort(perms.begin(), perms.end());
    perms.erase(unique(perms.begin(), perms.end()), perms.end());

    return perms;
}

vector<vector<int>> find_permutations(vector<int> arr, int n, int pos) {
    vector<vector<int>> result = {};

    if(pos == n - 1) {
        result.push_back(arr);
        return result;
    } else {
        vector<int> perm;
        vector<vector<int>> perms;
        for(int i = pos; i < n; i++) {
             perm = arr;
             perm[pos] = arr[i];
             perm[i] = arr[pos];
             perms = find_permutations(perm, n, pos + 1);
             
            for(auto p : perms) 
                result.push_back(p);
        }
    }

    return result;
}