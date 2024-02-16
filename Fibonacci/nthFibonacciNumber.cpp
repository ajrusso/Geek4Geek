/** Fibonacci 
@file nthFibonacciNumber.cpp

@brief

@ingroup <add package name>

@author Joe Smith
Contact ajrusso@outlook.com
*/
#include <cstdio>
#include <vector>

using namespace std;

int nthFibonacciIterative(int);
int nthFibonacciRecursive(int);
int nthFibonacciDynamic(int);


int main() {

    printf("Iterative Function\n");
    for (int n = 0; n < 1; n++) {
        int result = nthFibonacciIterative(14521);
        printf("Fibonacci number %d = %d\n", n, result);
    }
    
    printf("\nRecursive Function\n");
    for (int n = 0; n <= 10; n++) {
        int result = nthFibonacciRecursive(n);
        printf("Fibonacci number %d = %d\n", n, result);
    }

    printf("\nDynamic Programming Function\n");
    for (int n = 0; n < 1; n++) {
        int result = nthFibonacciDynamic(14521);
        printf("Fibonacci number %d = %d\n", n, result);
    }
}

/*
Time complexity: O(n)
Auxillary space complexity:O(1) 
*/
int nthFibonacciIterative(int n) {
    unsigned long long a = 0, b = 1, c; 
    int i;

    if (n == 0) {
        return a;
    } else {
        for (i = 2; i <= n; i++) {
            c = (a + b) % 1000000007;
            a = b;
            b = c; 
        }
    }
    return b;
}

/*
Time complexity:  Exponential, as every function calls two other functions
Auxillary space complexity: O(n), as the maximum depth of the recursion tree is n
*/
int nthFibonacciRecursive(int n) {
     if (n <= 1) {
        return n;
     } else {
        return nthFibonacciRecursive(n - 2) + nthFibonacciRecursive(n - 1) % 1000000007;
     }
}

/*
Time complexity: O(n)
Auxillary space complexity: O(n) 
*/
int nthFibonacciDynamic(int n) {
    vector<unsigned long long> f(n + 2);

    f[0] = 0;
    f[1] = 1;

    for (int i = 2; i <= n; ++i) {
        f[i] = (f[i - 2] + f[i - 1]) % 1000000007;
    }
    return f[n];
}