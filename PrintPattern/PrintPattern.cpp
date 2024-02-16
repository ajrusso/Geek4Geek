/* 
Print a sequence of numbers starting with N, without using loop, where replace N with N - 5, until N > 0. After that replace N with N + 5 until N regains its initial value.

Example 1:

Input: 
N = 16
Output: 
16 11 6 1 -4 1 6 11 16
Explaination: 
The value decreases until it is greater than 0. After that it increases and stops when it becomes 16 again.
Example 2:

Input: 
N = 10
Output: 
10 5 0 5 10
Explaination: It follows the same logic as per the above example.
Your Task:
You do not need to read input or print anything. Your task is to complete the function pattern() which takes N as input parameters and returns a list containing the pattern.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
-105 ≤ N ≤ 105
*/

#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

vector<int> pattern(int);
void down(vector<int>&, int, int);
void up(vector<int>&, int, int);

int main() {
    int n = 100;
    vector<int> result;

    result = pattern(n);

    for(int i : result) {
        printf("%d ", i);
    }
}

vector<int> pattern(int N) {
    vector<int> result;
    result.push_back(N);
    down(result, N, N);
    up(result, result.back(), N);
    return result;
}

void down(vector<int>& a, int cur, int n) {
    if(cur > 0) {
        a.push_back(cur - 5);
        down(a, cur - 5, n);
    }
}

void up(vector<int>& a, int cur, int n) {
    if(cur != n) {
        a.push_back(cur + 5);
        up(a, cur + 5, n);
    }
}