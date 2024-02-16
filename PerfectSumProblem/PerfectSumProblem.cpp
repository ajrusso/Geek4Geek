#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int perfectSum(int[], int, int);


int main() {
    int arr[] = {1,2,3,4,5};
    int n = 5; //sizeof(arr) / sizeof(arr[0]);
    int sum = 10;
    int pSum;

    pSum = perfectSum(arr, n, sum);
    printf("The perfect sum is %d", pSum);
}

int recursivePerfectSum(int arr[], int n, int sum) {
    int pSum = 0;
    int swap = 0;

    if (n == 1) {
        return 0;
    } else {
        for (int i = 0; i < n; ++i) {
            if (arr[i] == sum) {
                ++pSum;
            } else if (arr[i] > sum) {
                continue;
            } else {
                swap = arr[n - 1];
                arr[n - 1] = arr[i];
                arr[i] = swap;        
                pSum += perfectSum(arr, n - 1, sum - arr[n - 1]); // % (int(pow(10, 9)) + 7);
            }
        }
    }

    return pSum; 
}