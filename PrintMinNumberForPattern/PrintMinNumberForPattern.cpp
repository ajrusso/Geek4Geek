/*
Given a pattern containing only I's and D's. I for increasing and D for decreasing. Devise an algorithm to print the minimum number following that pattern. Digits from 1-9 and digits can't repeat.

Example 1:

Input:
D
Output:
21
Explanation:
D is meant for decreasing, so we choose the minimum number among all possible numbers like 21,31,54,87,etc.
Example 2:

Input:
IIDDD
Output:
126543
Explanation:
Above example is self- explanatory,
1 < 2 < 6 > 5 > 4 > 3
  I - I - D - D - D
Your Task:

You don't need to read input or print anything. Your task is to complete the function printMinNumberForPattern() which takes the string S and returns a string containing the minimum number following the valid number.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ Length of String ≤ 8
*/

#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;

string printMinNumberForPattern(string);

int main() {
    string S = "IIDDIID";
    string result;

    result = printMinNumberForPattern(S);

    printf("%s", result.c_str());
}

string printMinNumberForPattern(string S) {
    string output = "1";
    int i = 0;
    int numDs = 0;
    
    while(i < S.length()) {
        if(S[i] == 'I') {
            output += char(48 + i + 2);
            numDs = 0;
        } else {
            output.insert(output.begin() + i - numDs, 1, char(48 + i + 2));
            numDs++;
        }
        i++;
    }

    return output;
}