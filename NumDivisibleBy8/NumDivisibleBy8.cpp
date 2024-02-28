/*
Check if Number is Divisible by 8

Given a string representation of a decimal number s, check whether it is divisible by 8.

Example 1:

Input:
s = "16"

Output:
1

Explanation:
The given number is divisible by 8,
so the driver code prints 1 as the output.

Example 2:

Input:
s = "54141111648421214584416464555"

Output:
-1

Explanation:
Given Number is not divisible by 8, 
so the driver code prints -1 as the output.
Your Task:
You don't need to read input or print anything.Your task is to complete the function DivisibleByEight() which takes a string s as the input and returns 1 if the number is divisible by 8, else it returns -1.

Expected Time Complexity: O(1).
Expected Auxillary Space: O(1).

Constraints:
1 <= Number represented by the string s < 106
*/

#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;

int DivisibleByEight(string);

int main() {
    string s = "452345234523452352345234523523523523452000";
    int result = DivisibleByEight(s);

    printf("%s %s divisible by 8", s.c_str(), (result == -1) ? "is not" : "is");

}

int DivisibleByEight(string s) {
    int n = s.length();
    
    if(n > 3)
        s = s.substr(n-3, n);

    if(stoi(s) % 8 == 0)
        return 1;
    else
        return -1;
}