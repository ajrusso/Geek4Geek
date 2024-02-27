/*
PowerSet

Given a string s of length n, find all the possible subsequences of the string s in lexicographically-sorted order.

Example 1:

Input : 
s = "abc"
Output: 
a ab abc ac b bc c
Explanation : 
There are a total 7 number of subsequences possible 
for the given string, and they are mentioned above 
in lexicgraphically sorted order.
Example 2:

Input: 
s = "aa"
Output: 
a a aa
Explanation : 
There are a total 3 number of subsequences possible 
for the given string, and they are mentioned above 
in lexicgraphically sorted order.
Your Task:
You don't need to read input or print anything. Your task is to complete the function AllPossibleStrings() which takes a string s as the input parameter and returns a list of all possible subsequences (non-empty) that can be formed from s in lexicographically-sorted order.

Expected Time Complexity: O( n*2n  )
Expected Space Complexity: O( n * 2n )

Constraints: 
1 <= n <= 16
s will constitute of lower case english alphabets
*/

#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> AllPossibleStrings(string);
void helper(string, vector<string>&, string);


int main() {
    string input = "abc";

    vector<string> result = AllPossibleStrings(input);

    for(string s : result) {
        printf("%s ", s.c_str());
    }
    printf("\n");
}

vector<string> AllPossibleStrings(string s) {
    vector<string> result;

    helper(s, result, "");
    sort(result.begin(), result.end());

    return result;
}

void helper(string s, vector<string>& result, string temp) {
    if(!s.length()) {
        if(temp == "")
            return;
        result.push_back(temp);
        return;
    }
    helper(s.substr(1), result, temp + s[0]);
    helper(s.substr(1), result, temp);
}