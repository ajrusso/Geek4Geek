#include <stdlib.h>
#include <stdio.h>
#include <vector>


using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* insertion(Node*, int);
void printCorners(Node*);
int max(int, int);
vector<int> getNodesAtDepth(Node*, int, vector<int>&);
void printHeight(vector<int>);
int maxHeight(Node*, int);
void levelOrderTraversal(Node*);


int main() {
    Node* root = NULL;

    root = insertion(root, 4);
    root = insertion(root, 2);
    root = insertion(root, 6);
    root = insertion(root, 1);
    root = insertion(root, 3);
    root = insertion(root, 5);
    root = insertion(root, 7);
    
    rootLeftRight(root);
    //printCorners(root);
    //int maxheight = maxHeight(root, 1);
}



void printCorners(Node* root) {
    if (root == NULL)
        return;

    for (int i = 1; i <= maxHeight(root, 1); ++i) {
        vector<int> nodes_at_height;
        nodes_at_height = getNodesAtDepth(root, i, nodes_at_height);
        if (nodes_at_height.size() == 1) 
            printf("%d ", nodes_at_height.front());
        else {
            printf("%d ", nodes_at_height.front());
            printf("%d ", nodes_at_height.back());
        }
    }
}

void levelOrderTraversal(Node* root) {
    if (root == NULL) {
        printf("N ");
    } else {
        printf("%d ", root->left->data);
        printf("%d ", root->right->data);
        rootLeftRight(root->left);
        rootLeftRight(root->right);
    }
}

int maxHeight(Node* root, int height) {
    if (root == NULL) {
        return height - 1;
    } else {
        int rh;
        int lh;
        rh = maxHeight(root->right, height + 1);
        lh = maxHeight(root->left, height + 1);
        return (rh > lh) ? rh : lh; 
    }
}

vector<int> getNodesAtDepth(Node* root, int depth, vector<int>& nodes_at_depth) {
    if (root == NULL) {
        return nodes_at_depth;
    } else {
        if (depth == 1) {
            nodes_at_depth.push_back(root->data);
        } else {
            getNodesAtDepth(root->left, depth - 1, nodes_at_depth);
            getNodesAtDepth(root->right, depth - 1, nodes_at_depth);
        }
    }
    return nodes_at_depth;
}

void printHeight(vector<int> nodes) {
    for (int i = 0; i < nodes.size(); ++i) {
        printf("%d ", nodes[i]);
    }
    printf("\n");
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

int max(int a, int b) {
    return (a > b)? a : b;
}