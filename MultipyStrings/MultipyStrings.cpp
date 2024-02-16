#include <string>
#include <iostream>
#include <cmath>


using namespace std;


string multiplyStrings(string, string);
void removeLeadZero(string &);
bool isProductNegative(string &, string &);


int main() {
    string s1 = "9";
    string s2 = "2433";
    string product = "";

    product = multiplyStrings(s1, s2);

    cout << s1 << " * " << s2 << " = " << product << endl;
}

// Takes 2 string inputs and returns a string product
// 
string multiplyStrings(string s1, string s2) {
    string product = "";
    bool ProductNegative = false;

    // Handle Negatives
    ProductNegative = isProductNegative(s1, s2);
    
    if (ProductNegative) {
        cout << "The product will be negative" << endl;
    } else {
        cout << "The product will be positive" << endl;
    }

    // Remove Leading Zeros
    removeLeadZero(s1);
    removeLeadZero(s2);

    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;

    // Multiply strings
    char c;
    int digit = 0;
    int productDigit = 0;
    int carry = 0;
    int k;
    int h;

    if ( (s1.length() == 1 && s1[0] == '0') || (s2.length() == 1 && s2[0] == '0' )){
        product = "0";
        return product;
    }

    k = 0;
    for (int i = s1.length() - 1; i >= 0; --i) {
        h = 0;
        for (int j = s2.length() - 1; j >= 0; --j) {  
            
            // Convert string char to int
            digit = (s1[i] - 48) * (s2[j] - 48) + carry;
            cout << "digit = " << digit << endl;

            if (h + k + 1 <= product.length()) {
                digit += int(product[product.length() - 1 - h - k] - 48);
            }

            if (digit >= 10) {
                carry = digit / 10;
                digit %= 10;
            } else {
                carry = 0;
            }

            c = char(digit + 48);

            if (h + k + 1 <= product.length()) {
                product[product.length() - 1 - h++ - k] = c;
            } else {
                product.insert(product.end() - k - h++, 1, c);
            }
        }

        if (carry) {
            product.insert(product.begin(), 1, char(carry + 48));
            carry = 0;
        }
        ++k;
    }

    if (ProductNegative) {
        product.insert(0, "-");
    }

    return product;
}

bool isProductNegative(string &factor1, string &factor2) {
    bool isFactor1Neg = false;
    bool isFactor2Neg = false;
    
    if (factor1[0] == '-') {
        isFactor1Neg = true;
        factor1.erase(0, 1);
    }

    if (factor2[0] == '-') {
        isFactor2Neg = true;
        factor2.erase(0, 1);
    }

    return isFactor1Neg ^ isFactor2Neg;
}

void removeLeadZero(string &str) {
    int i = 0;

    while(str[i] == '0') {
        ++i;
    }
    
    if (i == str.length()) {
        --i;
    }
    
    str.erase(0, i);
}