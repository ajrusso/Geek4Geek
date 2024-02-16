// Subarray With a Given Sum
// author: Anthony Russo
// Date: 08/18/2023

#include <vector>

using namespace std;


vector<int> subarraySum(vector<int>, int, long long);


int main() {
    vector<int> arr = {1,2,3,4};
    vector<int> result;
    long long s = 0;


    result = subarraySum(arr, size(arr), s);

    for (int i = 0; i < size(result); ++i) {
        printf ("%d ", result[i]);
    }
}

vector<int> subarraySum(vector<int> arr, int n, long long s) {
    vector<int> result = {1};
    long long sum = 0;
    int left_index = 1;
    int right_index;

    for (right_index = 1; right_index <= n; ++right_index) {
        sum += arr[right_index - 1]; 
        printf("sum = %I64d\n", sum);
        
        while (sum > s) {
            printf("Sum too large: %I64d - %d = ", sum, arr[left_index - 1]);
            sum -= arr[left_index - 1];
            printf("%I64d\n", sum);
            result[0] = ++left_index;
        }

        if (sum > 0 && sum == s) {
            result.push_back(right_index);
            return result;
        }
    }
    result[0] = -1;
    return result;
}