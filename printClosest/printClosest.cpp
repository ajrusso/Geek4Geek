#include <stdlib.h>
#include <stdio.h>
#include <vector>


using namespace std;


vector<int> printClosest(int[], int[], int, int,int);
vector<int> printClosestSorted(int[], int[], int, int,int);


int main()
{
    int n = 1;
    int m = 6;
    int arr[] = {3};
    int brr[] = {3,5,4,1,3,1};
    int x = 20;
    vector<int> sumClosestToX= printClosestSorted(arr, brr, n, m, x);

    printf("The pair whose sum is closest is {%d, %d}\n", sumClosestToX[0], sumClosestToX[1]);
}

vector<int> printClosest(int arr[], int brr[], int n, int m, int x)
{
    vector<int> closestPair = {0,0};
    int closestSum = INT_MAX;

    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            printf("Sum of %d and %d is %d\n", arr[i], brr[j], arr[i] + brr[j]);
            printf("Closest Sum = %d\n\n", abs(x - (arr[i] + brr[j])));
            if(abs(x - (arr[i] + brr[j])) < closestSum  && abs(x - (arr[i] + brr[j])) != 0)
            {
                closestSum = abs(x - (arr[i] + brr[j]));
                closestPair[0] = arr[i];
                closestPair[1] = brr[j];
            }   
        }
    }

    return closestPair;
}

vector<int> printClosestSorted(int arr[], int brr[], int n, int m, int x)
{
    int closestSum=INT_MAX;
    vector<int>closestPair(2);
    int i = 0;
    int j = m - 1;

    while(i < n && j >= 0)
    {
        int sum = arr[i] + brr[j];
        if(closestSum > abs(sum - x))
        {
            closestSum = abs(sum - x);
            closestPair[0] = arr[i];
            closestPair[1] = brr[j];
        }
        if(sum <= x)
            i++;
        else
            j--;
    }
    return closestPair;
}