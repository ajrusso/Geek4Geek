#include <stdlib.h>
#include <vector>

using namespace std;

vector<int> getLeaders(int[], int);


int main() {
    int a[] = {63,70,80,33,33,47,20};
    vector<int> leaders;

    int len = sizeof(a) / sizeof(*a);

    leaders = getLeaders(a, len);

    printf("leaders: ");
    for (int i: leaders)
        printf("%d ", i);
    printf("\n");
}

vector<int> getLeaders(int a[], int n) {
    vector<int> leaders;
    int maxRightSide = 0;
    
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] >= maxRightSide) {
            leaders.insert(leaders.begin(), a[i]);
        }
        
        if (a[i] > maxRightSide)
            maxRightSide = a[i];
    }

    return leaders;
}