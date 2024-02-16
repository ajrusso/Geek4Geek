#include <stdio.h>
#include <stdlib.h>
#include <vector>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

using namespace std;

int getCount(Node*, int);
int getCount(vector<Node*>, int, int, int);
Node* insertion(Node* root, int data);


int main() {
    Node* root = NULL;
    int cost = 6;
    int count = 0;

    root = insertion(root, 4);
    root = insertion(root, 2);
    root = insertion(root, 6);
    root = insertion(root, 1);
    root = insertion(root, 3);
    root = insertion(root, 5);
    root = insertion(root, 7);
    root = insertion(root, 8);

    count = getCount(root, cost);
    printf("If budget %d, one can visit Max %d leaves", cost, count);
}

int getCount(Node *root, int k) {
    int count = 0;
    int depth = 1;
    vector<Node*> children;
    
    children.push_back(root);
    count = getCount(children, depth, k, count);

    return count;
}

int getCount(vector<Node*> children, int depth, int cost, int count) {
    if (children.empty() || cost == 0) {
        return count;
    } else {
        vector<Node*> new_children;
        for (auto it = children.begin(); it != children.end() && cost > 0; ++it) {
            if ((*it)->left == NULL && (*it)->right == NULL) {
                if (cost - depth >= 0) {
                    cost -= depth;
                    ++count;
                }
            } else {
                if ((*it)->left)
                    new_children.push_back((*it)->left);
                if ((*it)->right)
                    new_children.push_back((*it)->right);
            }
        }
        count = getCount(new_children, depth + 1, cost, count);
    }
    return count;
}

Node* insertion(Node* root, int data) {
    if (root == NULL) {
        Node* newNode = (Node*)(malloc(sizeof(Node)));
        newNode->data = data;
        newNode->right = NULL;
        newNode->left = NULL;
        root = newNode;
    } else {
        if (data < root->data)
            root->left = insertion(root->left, data);
        else 
            root->right = insertion(root->right, data);
    }

    // Add code to balance insert for AVL trees

    return root;
}