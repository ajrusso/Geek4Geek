#include <stdio.h>
#include <stdlib.h>
#include <queue>

using namespace std;

void shuffleArray(int[], int);

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = 10;

    shuffleArray(arr, n);

    for(int i: arr)
        printf("%d ", i);
}

void shuffleArray(int arr[], int n) {
    int* a = &arr[0];
    int* b = &arr[n/2];
    queue<int> q;

    if(n > 2) {
        while(b <= &arr[n - 1]) {
            q.push(*a);
            q.push(*(a + 1));
            *(a++) = q.front();
            q.pop();
            *(a++) = *b++;
        }
    }
}