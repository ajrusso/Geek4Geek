#include <stdlib.h>
#include <stdio.h>
#include <vector>


using namespace std;


void convertToWave(int, vector<int>&);


int main()
{
    int n = 8;
    vector<int> arr = {0,1,3,5,6,10,17,18};

    convertToWave(n, arr);

    printf("{");
    for(int i = 0; i < n; ++i)
    {
        (i == n - 1) ? printf("%d", arr[i]) : printf("%d, ", arr[i]); 
    }
    printf("}");
}
  
void convertToWave(int n, vector<int>& arr)
{
    if(n > 1)
    {
        for(int i = 0; i < n - 1; ++i)
        {
            if(i % 2)
            {
                if(arr[i] > arr[i + 1])
                {
                    int temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                }
            }
            else
            {
                if(arr[i] < arr[i + 1])
                {
                    int temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                }
            }
        }
    }
}