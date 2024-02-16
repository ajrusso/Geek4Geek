/*
Flatten BST to Sorted List

You are given a Binary Search Tree (BST) with n nodes, each node has a distinct value assigned to it. The goal is to flatten the tree such that, the left child of each element points to nothing (NULL), and the right child points to the next element in the sorted list of elements of the BST (look at the examples for clarity). You must accomplish this without using any extra storage, except for recursive calls, which are allowed.

Note: If your BST does have a left child, then the system will print a -1 and will skip it, resulting in an incorrect solution.

Example 1:

Input:
          5
        /    \
       3      7
      /  \    /   \
     2   4  6     8

Output: 2 3 4 5 6 7 8

Explanation: 
After flattening, the tree looks
like this
    2
     \
      3
       \
        4
         \
          5
           \
            6
             \
              7
               \
                8
Here, left of each node points
to NULL and right contains the
next node.

Example 2:

Input:
       5
        \
         8
       /   \
      7     9  

Output: 5 7 8 9

Explanation:
After flattening, the tree looks like this:
   5
    \
     7
      \
       8
        \
         9
Your Task:
You don't need to read input or print anything. Your task is to complete the function flattenBST() which takes root node of the BST as input parameter and returns the root node after transforming the tree.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= Number of nodes <= 103
1 <= Data of a node <= 105
*/

#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* flattenBST(Node*);
void printBST(Node*);


int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);
    

    Node* result = flattenBST(root);

    printBST(result);
}

Node* flattenBST(Node* root) {
    if(root == NULL) {
        return root;
    } else {
        Node* flat_right = flattenBST(root->right);
        root->right = flat_right;

        if(root->left == NULL) {
            return root;
        } else {
            Node* flat_left_head = flattenBST(root->left);
            Node* flat_left = flat_left_head;
            while(flat_left->right) {
                flat_left->left = NULL;
                flat_left = flat_left->right;
            }
            flat_left->right = root;
            root->left = NULL;
            return flat_left_head;
        }
    }
}

void printBST(Node* root) {
    if(root->right == NULL) {
        printf("%d", root->data);
    } else {
        printf("%d -> ", root->data);
        printBST(root->right);
    }
}