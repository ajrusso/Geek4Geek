#include <stdlib.h>
#include <stdio.h>

using namespace std;


struct Node {
    int data;
    int height;
    Node* left;
    Node* right;
};

Node* insertion(Node*, int);
Node* deleteNode(Node*, int);
Node* searching(Node*, int);
Node* minValue(Node*);
Node* rightRotate(Node*);
Node* leftRotate(Node*);
int getBalance(Node*);
int height(Node*);
int max(int, int);


int main() {
    Node* root = NULL;

    root = insertion(root, 4);
    root = insertion(root, 2);
    root = insertion(root, 6);
    root = insertion(root, 1);
    root = insertion(root, 3);
    root = insertion(root, 5);
    root = insertion(root, 7);
    //root = deleteNode(root, 4);
    root = deleteNode(root, 1);
    //root = deleteNode(root, 3);
    root = deleteNode(root, 6);
}


Node* deleteNode(Node* root, int data) {
    // Find Node
    if (root == NULL) {
        return root;
    } else {
        if (data == root->data) {
            Node* temp;
            // Delete the node
            //  - Decide if a shift is needed
            // Case 1) No Children
            if (root->left == NULL && root->right == NULL) {
                root = NULL;
            }
            // Case 2) One Child
            else if (root->left == NULL) {
                root = root->right;
                --(root->height);
            }
            else if (root->right == NULL) {
                root = root->left;
                --(root->height);
            }
            // Case 3) Two Children
            else {
                temp = minValue(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        } else if (data < root->data) {
            root->left = deleteNode(root->left, data);
        } else {
            root->right = deleteNode(root->right, data);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);
 
    // Left Right Case
    if (balance > 1 &&
        getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
 
    // Right Right Case
    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);
 
    // Right Left Case
    if (balance < -1 &&
        getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node* minValue(Node* root) {
    if (root->left == NULL) {
        return root;
    } else {
        root = minValue(root->left);
    }
    return root;
}

int getBalance(Node* root) {
     if (root == NULL)
        return 0;
    return height(root->left) - height(root->right); 
}

int height(Node* root) {
    if (root == NULL)
        return 0;
    return root->height;
}

int max(int a, int b) {
    return (a > b)? a : b;
}

Node* leftRotate(Node* x) {
    Node *y = x->right;
    Node *T2 = y->left;
 
    y->left = x;
    x->right = T2;
 
    x->height = max(height(x->left),
                    height(x->right)) + 1;
    y->height = max(height(y->left),
                    height(y->right)) + 1;
 
    return y;
}

Node* rightRotate(Node* y) {
    Node *x = y->left;
    Node *T2 = x->right;
 
    x->right = y;
    y->left = T2;
 
    y->height = max(height(y->left),
                    height(y->right)) + 1;
    x->height = max(height(x->left),
                    height(x->right)) + 1;
 
    return x;
}


Node* insertion(Node* root, int data) {
    if (root == NULL) {
        Node* newNode = (Node*)(malloc(sizeof(Node)));
        newNode->data = data;
        newNode->height = 1;
        newNode->right = NULL;
        newNode->left = NULL;
        root = newNode;
    } else {
        if (data < root->data)
            root->left = insertion(root->left, data);
        else 
            root->right = insertion(root->right, data);
    }

    root->height = 1 + max(height(root->left), height(root->right));

    // Add code to balance insert

    return root;
}

Node* searching(Node* root, int data) {
    return root;
}