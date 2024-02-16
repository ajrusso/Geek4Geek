#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>


using namespace std;

vector<vector<int>> fourSum(vector<int> &, int);

int main() 
{
    vector<vector<int>> sums;
    vector<int> arr = {0,0,2,1,1};
    int k = 3;

    sums = fourSum(arr, k);

}

vector<vector<int>> fourSum(vector<int> &arr, int k) 
{
    vector<vector<int>> sums = {};

    sort(arr.begin(), arr.end());


    for(int i = 0; i < arr.size(); ++i)
    {
        printf("%d, ", arr[i]);
    }

    return sums;
}