#include <stdlib.h>
#include <stdio.h>

using namespace std;


int FindMaxSum(int[], int);


int main() {
    int arr[] = {6,5,5,7,4};
    int n = 5;

    int maxSum = FindMaxSum(arr, n);
    printf("The Max Sum is %d", maxSum);

}

int FindMaxSum(int arr[], int n) {
    int sum = 0;
    if(n == 0) {
        return sum;
    } else if(n == 1) {
        return arr[0];
    } else if(n == 2) {
        if (arr[0] > arr[1]) {
            return arr[0];
        } else {
            return arr[1];
        }
    } 
}