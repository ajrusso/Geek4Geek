/*
Check if Frequences Can be Equal

Given a string s which contains only lower alphabetic characters, check if it is possible to remove at most one 
character from this string in such a way that frequency of each distinct character becomes same in the string. 
Return true if it is possible to do else return false.

Note: The driver code print 1 if the value returned is true, otherwise 0.

Example 1:

    Input:
    s = "xyyz"

    Output: 
    1 

    Explanation: 
    Removing one 'y' will make frequency of each character to be 1.

Example 2:

    Input:
    s = "xxxxyyzz"

    Output: 
    0

    Explanation: 
    Frequency can not be made same by removing at most one character.

Your Task:  
You dont need to read input or print anything. Complete the function sameFreq() which takes a string as input 
parameter and returns a boolean value denoting if same frequency is possible or not.

Expected Time Complexity: O(|s|) 
Expected Auxiliary Space: O(1)

Constraints:
1 <= |s| <= 105
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool samefreq(string);

int main() {
    string s = "xyyz";
    bool result = samefreq(s);
    
    cout << "The same frequency " << (result ? "is " : "is not ") << "possible" << endl;
}

bool samefreq(string s) {
    unordered_map<char, int> umap = {};
    int numChars = 0;
    int maxChars = 0;
    bool removedChar = false;

    for(char c : s) {
        if(umap.find(c) == umap.end()) {
            umap[c] = 1;
            numChars++;
        } else {
            umap[c]++;
        }
    }

    maxChars = s.size() / numChars;

    for(auto itr = umap.begin(); itr != umap.end(); itr++) {
        if(itr->second > maxChars || itr->second < maxChars) {
            if((itr->second == maxChars + 1 | itr->second == maxChars - 1) && !removedChar) {
                removedChar = true;
            } else {
                return false;
            }
        } 
    }
    return true;
}