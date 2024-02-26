/*
Distinct Occurences

Given two strings s and t of length n and m respectively. Find the count of distinct occurrences of t in s as a sub-sequence modulo 109 + 7.

Example 1:

Input:
s = "banana" , t = "ban"
Output: 
3
Explanation: 
There are 3 sub-sequences:[ban], [ba n], [b an].
Example 2:

Input:
s = "geeksforgeeks" , t = "ge"
Output: 
6
Explanation: 
There are 6 sub-sequences:[ge], [ge], [g e], [g e] [g e] and [g e].
Your Task:
You don't need to read input or print anything.Your task is to complete the function subsequenceCount() which takes two strings as argument s and t and returns the count of the sub-sequences modulo 109 + 7.

Expected Time Complexity: O(n*m).
Expected Auxiliary Space: O(n*m).

Constraints:
1 ≤ n,m ≤ 1000
*/

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int subsequenceCount(string, string);

int main() {
    string s = "bananas";
    string t = "baz";

    int result = subsequenceCount(s, t);

    printf("The number of distinct occurrences of \"%s\" and \"%s\" is %d", s.c_str(), t.c_str(), result);
}

int subsequenceCount(string s, string t) {
    int mod = 1e9 + 7;
    int m = t.size();
    int n = s.size();
    vector<int> instances(m + 1, 0);
    instances[0] = 1;
    
    for(int i = 1; i <= n; i++) {
        for(int j = m; j >= 1; j--) {
            if(t[j - 1] == s[i - 1]) {
                instances[j] = (instances[j - 1] + instances[j]) % mod;
            }
        }
    }

    return instances[m] % mod;
}