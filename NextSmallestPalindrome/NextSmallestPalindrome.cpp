// Palindrome - a word, phrase, or sequence that reads the same backward as forward, e.g., madam or nurses run

#include <vector>


using namespace std;


vector<int> generateNextPalindrome(int[], int);
bool incrementMiddle(int[], int);


int main() {
    int num[] = {9,9,9};
    bool response;
    response = incrementMiddle(num, sizeof(num) / sizeof(num[0]));
    printf("increment middle: %d\n", response);
    
    generateNextPalindrome(num, sizeof(num) / sizeof(num[0]));
}

// Do the Center values need to be incremented?
bool incrementMiddle(int num[], int n) {
    if (n == 1) {
        return true;
    }

    int middle = (n + 2 -1) / 2 - 1;
    for (int i = middle - n % 2, j = 1; i >= 0; --i, ++j ) {
        printf("compare %d and %d\n", num[i], num[middle + j]);
        if (num[i] > num[middle + j]) {
            return false;
        } else if (num[i] < num[middle + j]) {
            return true;
        }
    }
    return true;
}

vector<int> generateNextPalindrome(int num[], int n) {
    vector<int> v;
    int middle;
    int new_middle;
    int carry_one = 0;

    v.assign(n, 0);

    // Find middle values
    middle = num[n / 2 + n % 2 -1];

    if (incrementMiddle(num, n)) {
        (middle == 9) ? new_middle = 0 : new_middle = middle + 1;
        printf("middle = %d\n", middle);
        printf("new middle = %d\n", new_middle);

        // Add middle digit to the output vector
        if (n % 2 == 0 ) {
            v[n / 2 + n % 2 -1] = new_middle;
            v[n / 2 + n % 2] = new_middle;
        } else {
            v[n / 2 + n % 2 -1] = new_middle;
        }
        (new_middle == 0) ? carry_one = 1 : carry_one = 0;
    } else {
        if (n % 2 == 0 ) {
            v[n / 2 + n % 2 -1] = middle;
            v[n / 2 + n % 2] = middle;
        } else {
            v[n / 2 + n % 2 -1] = middle;
        }
    }

    // Add next palindrome to output vector
    int next;
    for (int i = n / 2 + n % 2 - 2; i >= 0 ; --i) {
        next = num[i];
        if (carry_one) {
            next += 1;
            if (next == 10) {
                next = 0;
            } else {
                carry_one = 0;
            }
        }
        v[i] = next;
        v[n - i - 1] = next;
    }

    if (carry_one) {
        auto it = v.begin();
        it = v.insert(it, 1);
        v[n] = 1;
    }

    return v;
}