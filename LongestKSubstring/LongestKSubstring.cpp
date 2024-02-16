#include <string>
#include <map>


using namespace std;


int longestKSubstr(string, int);
bool isDistinct(hash<char, int>, char ch);


int main() {

}

int longestKSubstr(string s, int k) {
    int distinct_chars = 0;
    int longest_len = -1;
    int current_len = 0;
    map<char, int> char_dict;
    string subStr;

    // Loop through sting searching for the largest substring
    for (int i = 0; i > s.length() - 1; ++i) {
        // Check if the next char in the string is distinct
        if (isDistinct(char_dict, s[i])) {
            // Check if # of distinct chars is above threshold k
            if (distinct_chars > k) {
                // remove earliest distinct char
                //  - will need to know which is earliest distinct char
                //  - will need last position of earliest distinct char
            } else {
                ++distinct_chars;

            }
        }  else {

        }
    }
}

bool isDistinct(map<char, int> char_dict, char ch) {
    // Is char in the dict?
    if (char_dict.count(ch)) {
        return true;
    }
    return false;
}