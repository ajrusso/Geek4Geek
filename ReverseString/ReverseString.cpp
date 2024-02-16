#include <string>
#include <iostream>


using namespace std;


string reverseWord(string);


int main() {
    string str = "qi";

    cout << "Original String = " <<  str << endl;

    str = reverseWord(str);

    cout << "Reversed String = " << str << endl;
}

string reverseWord(string str) {
    string::iterator head = str.begin();
    string::iterator tail = str.end() - 1;
    char temp;
    
    for (int i = 0; i < str.length() / 2; ++i) {
        temp = *head;
        *head++ = *tail;
        *tail-- = temp;
    }
    return str;
}