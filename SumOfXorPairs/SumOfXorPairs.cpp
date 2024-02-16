/*
Given an array of N integers, find the sum of xor of all pairs of numbers in the array arr. In other words, select all possible pairs of i and j from 0 to N-1 (i<j) and determine sum of all (arri xor arrj).

Example 1:

Input : arr[ ] = {7, 3, 5}
Output : 12
Explanation:
All possible pairs and there Xor
Value: ( 3 ^ 5 = 6 ) + (7 ^ 3 = 4)
 + ( 7 ^ 5 = 2 ) =  6 + 4 + 2 = 12
Example 2:

Input : arr[ ] = {5, 9, 7, 6} 
Output :  47
Explanation:
All possible pairs and there Xor
Value: (5 ^ 9 = 12) + (5 ^ 7 = 2)
 + (5 ^ 6 = 3) + (9 ^ 7 = 14)
 + (9 ^ 6 = 15) + (7 ^ 6 = 1)
 = 12 + 2 + 3 + 14 + 15 + 1 = 47
Your Task:
You do not have to take input or print output. You only need to complete the function sumXOR() that takes an array (arr), sizeOfArray (n), and return the sum of xor of all pairs of numbers in the array.

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).

Constraints
2 ≤ n ≤ 105
1 ≤ arr[i] ≤ 105
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>


using namespace std;


long long int sumXornTime(int[], int);
long long int sumXorn2Time(int[], int);


int main() {
    int arr[] = {7,3,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long int sum;

    sum = sumXornTime(arr, n);

    printf("Sum of XOR of all pairs of number int he array is %d", sum);
}

// O(n2)
long long int sumXorN2time(int arr[], int n) {
    long long int sum = 0;
    
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            sum += arr[i] ^ arr[j];
        }
    }
    
    return sum;   
}

// O(n)
// 2^Bit Position(LSB) * Sum of Set Bits in Position * Sum of Unset Bits in Position
long long int sumXornTime(int arr[], int n) {
    long long int setBits;
    long long int unsetBits;
    long long int sum;
    int mask;
    
    sum = 0;
    for(int i = 0; i < 31; i++) {
        setBits = 0; 
        unsetBits = 0;
        mask = 1 << i;
        for(int j = 0; j < n; j++) {
            if(mask & arr[j])
                ++setBits;
            else
                ++unsetBits;
        }
        sum += int(pow(2,i)) * setBits * unsetBits;
    }

    return sum;
}