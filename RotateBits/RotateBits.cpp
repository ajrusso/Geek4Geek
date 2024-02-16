#include <stdlib.h>
#include <stdio.h>
#include <vector>


using namespace std;
#define INT_BITS 16


vector<int> rotate(int, int);


int main () {
    vector<int> output;
    int n = 18;
    int d = 20;

    output = rotate(n, d);

    for (auto &answer : output) {
        printf("Answer: %d\n", answer);
    }
}

vector<int> rotate(int n, int d) {
    vector<int> output;
    unsigned short shift;

    printf("n = %d\n", n);
    
    // Rotate Left
    shift = (n << d % 16) | (n >> (INT_BITS - d %16));
    output.push_back(shift);
    printf("left = %d\n", shift);

    // Rotate Right
    shift = (n >> d % 16) | (n << (INT_BITS - d %16));
    output.push_back(shift);
    printf("left = %d\n", shift);

    return output;
}