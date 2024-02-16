#include <string>
#include <iostream>

using namespace std;

int LCS_Recursive(int, int, string, string);
int LCS_Dynamic(int, int, string, string);
int max(int, int);


int main() {
    string s1 = "ACABBBBDBAAB";
    string s2 = "BBCCBEECDCDE";
    int common = 0;
    
    common = LCS_Recursive(s1.length(), s2.length(), s1, s2);
    printf("The length of the longest common subsequence is %d", common);
}

int LCS_Recursive(int n, int m, string s1, string s2) {
    int count = 0;

    if (n == 0 || m == 0) {
        return 0;
    } 
    if (s1[n - 1] == s2[m - 1]) {
        return 1 + LCS_Recursive(n - 1, m - 1, s1, s2);
    } else {
        return max(LCS_Recursive(n, m -1, s1, s2), LCS_Recursive(n - 1, m, s1, s2));
    }

    return count;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int LCS_Dynamic(int n, int m, string s1, string s2) {
    // add dynamic code
}