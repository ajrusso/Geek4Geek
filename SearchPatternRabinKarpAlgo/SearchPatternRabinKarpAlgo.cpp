/*
Search Pattern (Rabin-Karp Algorithm)

Given two strings, one is a text string and other is a pattern string. The task is to print the indexes of all the occurences
 of pattern string in the text string. For printing, Starting Index of a string should be taken as 1. The strings will only 
 contain lowercase English alphabets ('a' to 'z').

Example 1:

    Input: 
    text = "birthdayboy"
    pattern = "birth"
    
    Output: 
    [1]
    
    Explanation: 
    The string "birth" occurs at index 1 in text.

Example 2:

    Input:
    text = "geeksforgeeks"
    pattern = "geek"

    Output: 
    [1, 9]

    Explanation: 
    The string "geek" occurs twice in text, one starts are index 1 and the other at index 9.

Your Task:
You don't need to read input or print anything. Your task is to complete the function search() which takes the string text 
and the string pattern as input and returns an array denoting the start indices (1-based) of substring pattern in the string text. 

Expected Time Complexity: O(|text| + |pattern|).
Expected Auxiliary Space: O(1).

Constraints:
1<=|text|<=5*10^5
1<=|pattern|<=|text|
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> search(string, string);

int main() {
    string pattern = "birth";
    string text = "birthbirthbirth";

    vector<int> result = search(pattern, text);

    cout << "[ ";
    for(int i = 0; i < result.size(); i++) {
        if(i < result.size() - 1)
            cout << result[i] << ", ";
        else 
            cout << result[i] << " ]" << endl;
    }
}

vector<int> search(string pattern, string text) {
    vector<int> result;
    int m = pattern.size();
    int n = text.size();
    int d = 264;   // Base: usually # of char in alphabet
    int q = 101;   // Prime Number: reduce collisions
    int p = 0;     // Hash value of pattern
    int t = 0;     // Hash value of text
    int h = 1;     // Hash value

    // Calculate hash value "pow(d, m - 1) % q"
    for(int i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }
    
    // Calculate the hash value for the pattern and first window of text
    for(int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Match Pattern: Slide the pattern across the text. If the pattern matches, collisions
    // may exist, so check each char individually. 
    for(int i = 0; i <= n - m; i++) {
        if(p == t) {
            // Check characters one by one
            int j;
            for(j = 0; j < m; j++) {
                if(pattern[j] != text[i+j])
                    break;
            }
            
            if(j == m)
                result.push_back(i + 1);
        } else {
            // pattern doesn't match current text window. Calculate the hash for the new text
            // window by adding the next char and removing the first.
            t = (d * (t - text[i] * h) + text[m + i]) % q;

            // Negative value for the text hash is possible
            if(t < 0)
                t += q;
        }
    }

    return result;
}