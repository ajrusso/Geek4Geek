/*
Given an integer, check whether it is Bleak or not.

A number n is called Bleak if it cannot be represented as sum of a positive number x and set bit count in x, i.e., x + countSetBits(x) is not equal to n for any non-negative number x.

Example 1:

    Input: 
        4
    Output: 
        1
Explanation: 
    There is no x such that x + countSetbit(x) = 4

Example 2:

    Input: 
        3
    Output: 
        0
Explanation: 
    3 is a Bleak number as 2 + countSetBit(2) = 3.
Your Task:
    You don't need to read or print anything. Your task is to complete the function is_bleak() which takes n as input parameter and returns 1 if n is not a Bleak number otherwise returns 0.

Expected Time Complexity: O(log(n) * log(n))
Expected Space Complexity: O(1)
 
Constraints:  1 <= n <= 109
*/

#include <stdlib.h>
#include <stdio.h>

using namespace std;

int is_bleak(int);
int countSetBits(int n);

int main() {
    int n = 3;
    int isBleak;

    isBleak = is_bleak(n);
    
    if(isBleak)
        printf("There is no x such that x + countSetbit(x) = %d", n);
    else
        printf("%d is a Bleak number", n);
}

int is_bleak(int n) {
    int i = 1;
    
    while((1 << i) < n)
        i++;

    for(int j = n - i; j < n; j++) {
        if(j + countSetBits(j) == n)
            return 0;
    }
    
    return 1;
}

int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}