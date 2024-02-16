/*
Shortest Prime Path

You are given two four digit prime numbers Num1 and Num2. Find the distance of the shortest path from Num1 to Num2 that can be attained by altering only single digit at a time such that every number that we get after changing a digit is a four digit prime number with no leading zeros.

Example 1:

Input:
Num1 = 1033 
Num2 = 8179
Output: 6
Explanation:
1033 -> 1733 -> 3733 -> 3739 -> 3779 -> 8779 -> 8179.
There are only 6 steps reuired to reach Num2 from Num1. 
and all the intermediate numbers are 4 digit prime numbers.
Example 2:

Input:
Num1 = 1033 
Num2 = 1033
Output:
0
Your Task:  
You don't need to read input or print anything. Your task is to complete the function solve() which takes two integers Num1 and Num2 as input parameters and returns the distance of the shortest path from Num1 to Num2. If it is unreachable then return -1.

Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)

Constraints:
1000<=Num1,Num2<=9999
Num1 and Num2 are prime numbers.
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

int solve(int, int);
bool isPrime(int);

int main() {
    int Num1 = 1033;
    int Num2 = 8179;

    int result = solve(Num1, Num2);

    printf("There are %d steps required to go from %d -> %d", result, Num1, Num2);
}

int solve(int Num1, int Num2) {
    int steps = 0;
    int num_digits = 4;
    int cur = Num1;
    int digit = 0;
    int num = 0;

    while (cur < Num2) {
        // Find the greatest prime
        // check each digit from 9 -> cur digit
        for(int i = 3; i >= 0; i--) {
            digit = cur / int(pow(10, i));
            for(int j = 9; j > digit; j--) {
                int num = j * int(pow(10, i)) + cur - int(pow(10, i));
                if(num <= Num2) {
                  if(isPrime(num)) {
                    cur = num;
                    steps++;
                    printf("%d\n",cur);
                    break;
                  }
                }
            }
        }
    }

    return steps;
}

bool isPrime(int n) {
    if (n <= 1)
        return false;
 
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;

    return true;
}