// Given a number N. Find the minimum number of operations required to reach N starting from 0. You have 2 operations available:
//    - Double the number
//    - Add one to the number

#include <stdlib.h>
#include <stdio.h>

using namespace std;


int minOperation(int);


int main() {
    int n = 9
    ;
    int numOfOperations = 0;

    numOfOperations = minOperation(n);

    printf("Number of Operations: %d", numOfOperations);
}

int minOperation(int n) {
    int numOfOp = 1;

    if (n > 1) {
        ++numOfOp;
        while(n > 2) {
            if(n % 2) {
                n -= 1;
                ++numOfOp;
            } else {
                n /= 2;
                ++numOfOp;
            }
        }
    }

    return numOfOp;
}