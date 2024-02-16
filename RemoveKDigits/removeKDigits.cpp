/*
Remove K Digits

Given a non-negative integer S represented as a string, remove K digits from the number so that the new number is the smallest possible.
Note : The given num does not contain any leading zero.

Example 1:

Input:
S = "149811", K = 3
Output: 
111
Explanation: 
Remove the three digits 
4, 9, and 8 to form the new number 111
which is smallest.
Example 2:

Input:
S = "1002991", K = 3
Output: 
21
Explanation: 
Remove the three digits 1(leading
one), 9, and 9 to form the new number 21(Note
that the output must not contain leading
zeroes) which is the smallest.
Your Task:
You don't need to read input or print anything. Your task is to complete the function removeKdigits() which takes the string S and an integer K as input and returns the new number which is the smallest possible.

Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(|S|).

Constraints:
1<= K <= |S|<=106
*/
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <stack>

using namespace std;

string removeKdigits(string, int);

int main() {
    string S = "6802036147";
    int K = 1;
    string result = "";

    result = removeKdigits(S, K);

    if(result != "")
        printf("%d digits were removed from \"%s\" to form the new number \"%s\"", K, S.c_str(), result.c_str());
}

string removeKdigits(string S, int K) {
    stack<char> st;
    string result = "";

    // Load Stack With String Chars
    for(int i = 0; i < S.length(); i++) {
        while(!st.empty() && st.top() > S[i] && K) {
            st.pop();
            K--;
        }

        st.push(S[i]);
    }

    // If K chars have not been removed, remove the 
    while(K--) {
        st.pop();
    }

    // Push stack to result string (will be reversed)
    while(!st.empty()) {
        result.push_back(st.top());
        st.pop(); 
    }

    // Flip the reverse result string to the correct orientation 
    reverse(result.begin(), result.end());
    
    // Count # of leading zeros
    int j = 0;
    while(result[j] == '0')
        j++;
        
    // Return the remaining digits. If there are none, then return zero.
    return (j == result.size()) ? "0" : result.substr(j);
}