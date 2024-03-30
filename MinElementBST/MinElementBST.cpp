/*
Minimum Element in BST

Given the root of a Binary Search Tree. The task is to find the minimum valued element in this given BST.

Example 1:

    Input:
            5
            /    \
            4      6
        /        \
        3          7
        /
        1
    Output: 1

Example 2:

    Input:
                9
                \
                10
                    \
                    11
    Output: 9

Your Task:
The task is to complete the function minValue() which takes root as the argument and returns the minimum
element of BST. If the tree is empty, there is no minimum element, so return -1 in that case.

Expected Time Complexity: O(Height of the BST)
Expected Auxiliary Space: O(1).

Constraints:
0 <= n <= 104
*/

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

int minValue(Node*);
Node* newNode(int);

int main() {
    Node* root = newNode(5);
    root->left = newNode(4);
    root->left->left = newNode(3);
    root->left->left->left = newNode(2);
    root->right = newNode(6);
    root->right->right = newNode(7);

    int result = minValue(root);

    cout << "Minimum value of the BST is " << result << endl;
}

int minValue(Node* root) {
    if(!root)
        return -1;
    if(!(root->left))
        return root->data;
        
    return minValue(root->left);
}

Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}