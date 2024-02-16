#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;

    Node(int val) {
        data = val;
        right = NULL;
        left = NULL;
    }
};

bool isSymmetric(Node*);
bool isSymmetric(Node*, Node*);

int main() {
    Node* root = new Node(1);
    //root->left = new Node(2);
    root->right = new Node(3);
    bool result;

    result = isSymmetric(root);

    if(result)
        printf("Is symmetric");
    else
        printf("Is not symmetric");
}

bool isSymmetric(Node* root) {
    bool result = true;
    
    if(root)
        result = isSymmetric(root->left, root->right);
    
    return result;
}

bool isSymmetric(Node* l, Node* r) {
    if((l == NULL && r != NULL) || l != NULL && r == NULL)
        return false;

    if(l == NULL && r == NULL)
        return true;
    
    if(r->data != l->data)
        return false;

    if(!isSymmetric(l->left, r->right) || !isSymmetric(l->right, r->left))
        return false;

    return true;
}