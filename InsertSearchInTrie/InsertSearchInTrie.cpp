/*
Insert and Search in a Trie

Complete the Insert and Search functions for a Trie Data Structure. 

Insert: Accepts the Trie's root and a string, modifies the root in-place, and returns nothing.
Search: Takes the Trie's root and a string, returns true if the string is in the Trie, otherwise false.
Note: To test the correctness of your code, the code-judge will be inserting a list of N strings called into the Trie, and then will search for the string key in the Trie. The code-judge will generate 1 if the key is present in the Trie, else 0.

Example 1:

Input:
n = 8
list[] = {the, a, there, answer, any, by, bye, their}
key = the
Output: 1
Explanation: 
"the" is present in the given set of strings. 
Example 2:

Input:
n = 8
list[] = {the, a, there, answer, any, by, bye, their}
key = geeks
Output: 0
Explanation: 
"geeks" is not present in the
given set of strings.
Your Task:
You do not have to take any input or print anything. Complete insert and search functions. 

Expected Time Complexity: O(M+|key|)
Expected Auxiliary Space: O(M)
Here M = sum of the length of all strings which are present in the list[] 

Constraints:
1 <= N <= 104
1 <= length of list[i] <= 30
All strings will constitute of lowercase alphabets only.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;

struct TrieNode {
    struct TrieNode *children[26];

    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
};

void insert(TrieNode*, string);
bool search(TrieNode*, string);

int main() {
    string list[] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    string key = "there";
    int n = 8;

    // Create empty root TrieNode
    TrieNode* root = new TrieNode;
    root->isLeaf = false;
    for(int i = 0; i < 26; i++) {
        root->children[i] = NULL;
    }

    // Insert string list into TrieNode
    for(string word : list) {
        insert(root, word);
    }

    // Search for key in TrieNode
    bool result = search(root, key);

    if(result)
        printf("\"%s\" was found", key.c_str());
    else
        printf("\"%s\" was NOT found", key.c_str());
}

void insert(TrieNode *root, string key) {
    TrieNode *node = root;

    for(int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        
        if(!node->children[index]) {
            node->children[index] = new TrieNode;
            node->children[index]->isLeaf = false;

            for(int j = 0; j < 26; j++)
                node->children[index]->children[j] = NULL;
        }

        node = node->children[index];
    }

    node->isLeaf = true;
}

bool search(TrieNode *root, string key) {
    TrieNode *node = root;

    for(int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';

        if(node->children[index]) {
            node = node->children[index];
        } else {
            return false;
        }
    }

    return (node->isLeaf) ? true : false;
}