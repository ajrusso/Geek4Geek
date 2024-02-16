// Given an array a of size N which contains elements from 0 to N-1, you need to find all the elements
// occurring more than once in the given array. Return the answer in ascending order. If no such element
// is found, return list containing [-1]. 
//
// Note: The extra space is only for the array to be returned. Try and perform all operations within the provided array.

#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>


using namespace std;


vector<int> duplicates(long long [], int);
vector<int> duplicatesMap(long long [], int);
vector<int> duplicatesInOrder(long long [], int);


int main() {
    int n = 13;
    long long arr[] = {3,4,12,3,12,3,4,4,12,7,11,6,5};
    vector<int> dups;

    dups = duplicatesInOrder(arr, n);

    printf("Duplicates: {");
    for(int i = 0; i < dups.size(); ++i) {
        if(i == dups.size() - 1) {
            printf("%d", dups[i]);
        } else {
            printf("%d,", dups[i]);
        }
    }
    printf("}");
}

vector<int> duplicatesInOrder(long long arr[], int n) {
    vector<int> dups;

    sort(arr, arr + n);

    int cur = arr[0];
    int count = 1;
    for(int i = 1; i < n; i++) {
        if(cur == arr[i]) {
            count++;
            if (count == 2)
                dups.push_back(arr[i]);
        } else {
            cur = arr[i];
            count = 1;
        }
    }

    if(dups.empty()) 
        dups.push_back(-1);

    return dups;
}

vector<int> duplicatesMap(long long arr[], int n) {
    map<int,int> m;
    vector<int> dups;

    for(int i = 0; i < n; i++) {
        ++m[arr[i]];
        if(m[arr[i]] == 2) 
            dups.push_back(arr[i]);
    }

    if(dups.empty()) 
        dups.push_back(-1);

    return dups;
}

vector<int> duplicates(long long arr[], int n) {
    vector<int> dups;
    int i = 0;

    while(i < n) {
        if(arr[i] < 0) {
            ++i;
        } else if(arr[arr[i]] < 0) {
            if(arr[arr[i]] == -1) {
                dups.push_back(arr[i]);
            }
            arr[arr[i]] -= 1;
            ++i;
        } else {
            int temp = arr[i];
            arr[i] = arr[arr[i]];
            arr[temp] = -1;
        }
    }
    
    if(dups.empty()) {
        dups.push_back(-1);
    }

    return dups;
}