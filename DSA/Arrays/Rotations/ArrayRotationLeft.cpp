/*
Array Rotation Left

*/

#include <iostream>
#include <vector>

using namespace std;

void leftRotateV1(int[], int, int);
void leftRotateV2(int[], int, int);
void leftRotateV3(int[], int, int);
void leftRotateV4(int[], int, int);
int getGCD(int, int);
void reverse(int[], int, int);
void printArray(int[], int);


int main() {
    int arr[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    int d = 17;
    int n = 15;

    cout << "Original             :   ";
    printArray(arr, n);

    leftRotateV4(arr, d, n);

    cout << "Left Rotate " << d << " Times :   "; 
    printArray(arr, n);
}
 
void leftRotateV1(int arr[], int d, int n) {
    vector<int> temp = {};
    d %= n;

    for(int i = d; i < n; i++) {
        temp.push_back(arr[i]);
    }

    for(int i = 0; i < d; i++) {
        temp.push_back(arr[i]);
    }

    for(int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

void leftRotateV2(int arr[], int d, int n) {
    d %= n;
    while(d > 0) {
        int temp = arr[0];
        for(int i = 0; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        arr[n - 1] = temp;
        d--;
    }
}

void leftRotateV3(int arr[], int d, int n) {
    int gcd = getGCD(d, n);
    d %= n;

    for(int i = 0; i < gcd; i++) {
        int temp = arr[i];
        int j = i;
        while(true) {
            int k = j + d;
            
            if(k >= n)
                k -= n;
            
            if(k == i)
                break;
            
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }

}

int getGCD(int a, int b) {
    if(b == 0)
        return a;
    else
        return getGCD(b, a % b);
}

void leftRotateV4(int arr[], int d, int n) {
    d %= n;
    reverse(arr, 0, d - 1);
    reverse(arr, d, n - 1);
    reverse(arr, 0, n - 1);
}

void reverse(int arr[], int low, int high) {
    int temp = 0;
    if(low < high) {
        temp = arr[low];
        arr[low++] = arr[high];
        arr[high--] = temp;
    }
}

void printArray(int arr[], int n) {
    cout << "{";
    for(int i = 0; i < n - 1; i++) {
        cout << arr[i] << ", ";
    }
    cout << arr[n - 1] << "}" << endl << endl;
}