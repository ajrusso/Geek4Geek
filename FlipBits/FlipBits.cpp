#include <cstdio>


int maxOnes(int[], int);


int main() {
    int test1[] = {1,1,1,1,0,0,0,1,1,0,0,1,0,1,1,0,1,1,1,1,0,1,1,1,0,1,1,0,0,0,0,1,1,0,0,0,1,1,1,0,1,0,1,0,0,1,0,1,1,0,1,0,1,0,1,1,1,0,0,1,1,1,0,0,1,1,0,1,1,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0,0,1,0,0,1,1,0,1,1,1,1,0,0,1,1,0,0,0,1,1,0,1,1,0,1,1,1,0,1,0,0,0,0,1,0,1,1,0,0,1,0,1,0,0,1,1,0,1,0,0,0,0,1,1,0,1,0,1,1,0,0,1,1,0,1,1,0,1,0,0,1,0,0,1,0,1,0,0,0,0,0,0,1,0,0,1,0,0,1,0,1,1,0,0,0};
    int test2[] = {0,1,1,0,1,1,1,1};
    int test3[] = {0,1,0,0};
    int test4[] = {0,1,1,0};

    int n = sizeof(test1) / sizeof(int);
    printf("n is %d\n", n);
    printf("Test2 max ones is %d\n", maxOnes(test1, n));
}

// iterative approach
int maxOnes(int a[], int n) {
    int *first = NULL; 
    int *last = NULL;
    int onesBeforeFirstZero = 0;
    int onesBetweenZeros = 0;
    int onesAfterLastZero = 0;
    int lengthOfZeros = 0;
    int onesGained = 0;
    int max = 0;

    for (int i = 0; i < n; ++i) {
        // 1's before zero
        if (first == NULL && a[i] == 1) {
            ++onesBeforeFirstZero;
        // 0 found
        } else if (first == NULL && a[i] == 0) {
            first = &(a[i]);
            last = &(a[i]);
        // 1 found after last zero
        } else if (first != NULL && a[i] == 1){
            ++onesAfterLastZero;
        } else {
            lengthOfZeros = last - first + 1;
            if (lengthOfZeros - onesBetweenZeros <= onesBetweenZeros) {
                onesBeforeFirstZero += onesBetweenZeros;
                onesBetweenZeros = 0;
                first = &(a[i]);
                last = &(a[i]);
            } else {
                last = &a[i];
                onesBetweenZeros += onesAfterLastZero;
                onesAfterLastZero = 0;
            }
        }
    }
    lengthOfZeros = last - first + 1;
    onesGained = lengthOfZeros - onesBetweenZeros;
    return onesBeforeFirstZero + onesGained + onesAfterLastZero;
}