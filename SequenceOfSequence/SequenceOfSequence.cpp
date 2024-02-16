/*
Sequence of Sequence

Given two integers m and n, try making a special sequence of numbers seq of length n such that

seqi+1 >= 2*seqi 
seqi > 0
seqi < m
Your task is to determine total number of such special sequences possible.

Example 1:

Input: 
m = 10
n = 4
Output: 
4
Explaination: 
There should be n elements and 
value of last element should be at-most m. 
The sequences are {1, 2, 4, 8}, {1, 2, 4, 9}, 
{1, 2, 4, 10}, {1, 2, 5, 10}.
Example 2:

Input: 
m = 5
n = 2
Output: 
6
Explaination: 
The sequences are {1, 2}, 
{1, 3}, {1, 4}, {1, 5}, {2, 4}, {2, 5}.
Your Task:
You do not need to read input or print anything. Your task is to complete the function numberSequence() which takes the number m and n as input parameters and returns the number of possible special sequences.

Expected Time Complexity: O(m*n)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ m, n ≤ 100
*/

#include <stdlib.h>
#include <stdio.h>

int numberSequence(int, int);
int isSpecial(int, int, int);


int main() {
    int m = 10;
    int n = 4;
    int result;

    result = numberSequence(m, n);

    printf("The total number of special sequences is %d", result);
}

int numberSequence(int m, int n) {
    if(m == 0 || n == 1)
        return m;
    int result = 0;
    for(int i = m; i >= 1; i--)
        result += numberSequence(i / 2, n - 1);
    return result;
}