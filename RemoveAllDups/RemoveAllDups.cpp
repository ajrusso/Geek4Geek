/*
Remove All Dups From String

Given a string str which may contains lowercase and uppercase chracters. The task is to remove all 
 duplicate characters from the string and find the resultant string. The order of remaining characters
 in the output should be same as in the original string.

Example 1:

    Input:
     str = "geEksforGEeks"
    
    Output: 
     "geEksforG"
    
    Explanation: 
     After removing duplicate characters such as E, e, k, s, we have string as "geEksforG".

Example 2:

    Input: 
     str = "HaPpyNewYear"

    Output: 
     "HaPpyNewYr"

    Explanation: 
     After removing duplicate characters such as e, a, we have string as "HaPpyNewYr".
     Your Task:

    Complete the function removeDuplicates() which takes a string str, as input parameters and returns
     a string denoting the answer. You don't have to print answer or take inputs.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
    1 ≤ N ≤ 105
    String contains uppercase and lowercase english letters.
*/

#include <iostream>
#include <unordered_map>

using namespace std;

string removeDuplicates(string);

int main() {
    string str = "HaPpyNewYear";
    
    cout << "OG     = " << str << endl;
    string result = removeDuplicates(str);
    
    cout << "result = " << result << endl;
}

string removeDuplicates(string str) {
    unordered_map<char, int> umap = {};
    string result = "";
    
    for(int i = 0; i < str.length(); i++) {
        if(umap.find(str[i]) == umap.end()) { 
            umap[str[i]] = 1;
            result += str[i];
        } else {
            umap[str[i]]++;
        }  
    }
    
    return result;
}