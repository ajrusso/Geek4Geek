/*
Print N-Bit Binary Numbers Having More 1s Than 0s

Given a positive integer n. Your task is to generate a string list of all n-bit binary numbers where, 
for any prefix of the number, there are more or an equal number of 1's than 0's. The numbers should 
be sorted in decreasing order of magnitude.

Example 1:

    Input:  
    n = 2

    Output: 
    "11, 10"

    Explanation: Valid numbers are those where each prefix has more 1s than 0s:
    11: all its prefixes (1 and 11) have more 1s than 0s.
    10: all its prefixes (1 and 10) have more 1s than 0s.
    So, the output is "11, 10".

Example 2:

    Input:  
    n = 3

    Output: 
    "111, 110, 101"

    Explanation: Valid numbers are those where each prefix has more 1s than 0s.
    111: all its prefixes (1, 11, and 111) have more 1s than 0s.
    110: all its prefixes (1, 11, and 110) have more 1s than 0s.
    101: all its prefixes (1, 10, and 101) have more 1s than 0s.
    So, the output is "111, 110, 101".

User Task:
Your task is to complete the function NBitBinary() which takes a single number as input n and returns the 
list of strings in decreasing order. You need not take any input or print anything.

Expected Time Complexity: O(|2n|)
Expected Auxiliary Space: O(2n)

Constraints:
1 <= n <= 15
*/

#include <iostream>
#include <vector>

using namespace std;

vector<string> NBitBinary(int);


int main() {
    int n = 6;

    vector<string> result = NBitBinary(n);

    for(string s : result) {
        cout << "\"" << s << "\" "; 
    }   
}

vector<string> NBitBinary(int n) {
    vector<string> result = {};
    string s = "";

    for(int i = 0; i < n; i++) {
        s += '1';
    }
    result.push_back(s);

    while(s[0] == '1') {
        int i = n - 1;
        while(i >= 0) {
            if(s[i] == '1') {
                s[i] = '0';
                break;
            } else {
                s[i--] = '1';
            }
        }

        int count = 0;
        int prefix = 1;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1')
                count++;

            if(count < i + 1 - count) {
                prefix = 0;
                break;
            }
        }

        if(prefix)
            result.push_back(s);    
    }

    return result;
}