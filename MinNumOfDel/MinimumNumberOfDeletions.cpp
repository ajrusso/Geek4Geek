/*Given a string of S as input. Your task is to write a program to delete the minimum number of characters from the string so that the resultant string is a palindrome.
Note: The order of characters in the string should be maintained.

Example 1:

Input: 
S = "aebcbda"
Output: 
2
Explanation: 
Remove characters 'e' and 'd'.

Example 2:

Input: 
S = "geeksforgeeks"
Output: 
8
Explanation: 
One of the possible result string can be "eefee", so answer is 13 - 5 = 8.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function minimumNumberOfDeletions() which takes the string S as inputs and returns the minimum number of deletions required to convert S into a pallindrome.

Expected Time Complexity: O(|S|2)
Expected Auxiliary Space: O(|S|2)

Constraints:
1 ≤ |S| ≤ 103
*/

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>


using namespace std;


int minimumNumberOfDeletions(string);
int longestPalindrome(string&, string&, int, int);


int main() {
    string S = "cqreykpbfdftghvqqywnvrqrclnzikszfoyhebcrfosljzlbmtlfosigzmpariu"; // 63 chars, 46 dels is correct answer
    //string S = "abab";
    int result;

    result = minimumNumberOfDeletions(S);

    printf("The minimum number of deletions to turn string \"%s\" into a palindrome is %d", S.c_str(), result);
}

int minimumNumberOfDeletions(string S) {
    string t=S;
    reverse(t.begin(),t.end());
    int n = S.length();
    int ans = longestPalindrome(S, t, n-1, n-1);
    return n-ans;
}

int longestPalindrome(string& s1,string& s2,int i,int j) {
    if(i < 0 || j < 0)
        return 0;

    if(s1[i]==s2[j])
        return 1 + longestPalindrome(s1,s2,i-1,j-1);
    
    int a=longestPalindrome(s1,s2,i-1,j);
    int b=longestPalindrome(s1,s2,i,j-1);
    
    return max(a,b);
}