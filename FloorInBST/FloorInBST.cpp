#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct Node
{
    int data;
    Node *right;
    Node *left;
};


int floorBST(Node *, int);
Node* insertion(Node*, int);


int main()
{
    int x = 14;
    Node *root = NULL;
    int result;

    root = insertion(root, 12);
    root = insertion(root, 23);
    root = insertion(root, 5);
    root = insertion(root, 19);
    root = insertion(root, 16);
    root = insertion(root, 1);
    root = insertion(root, 17);
    root = insertion(root, 24);
    root = insertion(root, 20);
    root = insertion(root, 13);
    root = insertion(root, 14);
    root = insertion(root, 21);
    root = insertion(root, 10);
    root = insertion(root, 8);
    root = insertion(root, 15);

    result = floorBST(root, x);

    printf("Result is %d", result);
}

int floorBST(Node* root, int x)
{
    if(root == NULL)
        return -1;

    if(root->data == x)
        return x;
    else if (x < root->data)
    {
        while(root->left)
        {
            if(root->left->data == x)
                return x;
            else if (x > root->left->data)
            {
                root = root->left;
                while(root->right)
                {
                    root = root->right;
                    if(root->data == x)
                        return x;
                }
                return root->data;
            }
            else
                root = root->left;
        }
    }
    else
    {
        while(root->right)
        {
            if(root->right->data == x)
                return x;
            else if (x < root->right->data)
            {
                while(root->left)
                {
                    root = root->left;
                    if(root->data == x)
                        return x;
                }
                return root->data;
            } else
                root = root->right;
        }
    }
    
    return -1;
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

    return root;
}