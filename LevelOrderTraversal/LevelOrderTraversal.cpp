/*
Level Order Traversal

Given a root of a binary tree with n nodes, find its level order traversal.
Level order traversal of a tree is breadth-first traversal for the tree.

Example 1:

    Input:
        1
      /   \ 
     3     2
    
    Output:
    1 3 2

Example 2:

    Input:
            10
         /      \
        20       30
      /   \
     40   60

    Output:
    10 20 30 40 60

Your Task:
You don't have to take any input. Complete the function levelOrder() that takes the root node as 
input parameter and returns a list of integers containing the level order traversal of the given 
Binary Tree.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 ≤ n ≤ 105
0 ≤ Data of a node ≤ 109
*/

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

vector<int> levelOrder(Node*);


int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    root->left->left = new Node(6);
    root->left->right = new Node(7);

    vector<int> result = levelOrder(root);
    
    for(int i : result) {
        cout << i << " ";
    }
}

vector<int> levelOrder(Node* root) {
    vector<int> result;
    vector<Node*> level = {root};
    
    int i = 0;
    while(i < level.size()) {
        result.push_back(level[i]->data);
        
        if(level[i]->left)
            level.push_back(level[i]->left);
            
        if(level[i]->right)
            level.push_back(level[i]->right);
        
        i++;
    }

    return result;
}