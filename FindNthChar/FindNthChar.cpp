/*
Find the Nth Character

Given a binary string s. Perform r iterations on string s, where in each iteration 0 becomes
 01 and 1 becomes 10. Find the nth character (considering 0 based indexing) of the string 
 after performing these r iterations (see examples for better understanding).

Example 1:

    Input:
    s = "1100"
    r = 2
    n = 3
    
    Output:
    1
    
    Explanation: 
    After 1st iteration s becomes "10100101".
    After 2nd iteration s becomes "1001100101100110".
    Now, we can clearly see that the character at 3rd index is 1, and so the output.

Example 2:

    Input:
    s = "1010"
    r = 1
    n = 2
    
    Output:
    0
    
    Explanation : 
    After 1st iteration s becomes "10011001".
    Now, we can clearly see that the character at 2nd index is 0, and so the output.
    
    Your task:
    You don't need to read input or print anything. Your task is to complete the function
     nthCharacter() which takes the string s and integers r and n as input parameters and 
     returns the n-th character of the string after performing r operations on s.
    
Expected Time Complexity: O(r*|s|)
Expected Auxilary Space: O(|s|)
 
Constraints:
1 ≤ |s| ≤ 103
1 ≤ r ≤ 20
0 ≤ n < |s|
*/

#include <iostream>
#include <string>

using namespace std; 

char nthCharacter(string, int, int);

int main() {
    string s = "100001010";
    int r = 2;
    int n = 0;

    char result = nthCharacter(s, r, n);

    cout << "The Character at the index " << n << " is " << result << endl;
}

char nthCharacter(string s, int r, int n) {
    cout << "s = " << s << endl;
    string temp;
    for(int i = 0; i < r; i++) {
        temp.clear();
        for(int j = 0; j < n+1; j++){
            temp += s[j];
            
            if(s[j] == '1')
                temp += '0';
            else
                temp += '1';
        }
        s  = temp;
        cout << "s = " << s << endl;
    }
    return s[n];
}