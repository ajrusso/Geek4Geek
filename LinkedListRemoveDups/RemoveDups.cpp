#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* addNode(Node*, int);
Node* deleteNode(Node*, int);
Node* removeDuplicates(Node *head);
void printList(Node*);


int main() {
    Node* head = nullptr;
    head = addNode(head, 2);
    head = addNode(head, 2);
    head = addNode(head, 2);
    head = addNode(head, 2);
    head = addNode(head, 2);
    head = addNode(head, 3);
    head = addNode(head, 3);
    head = addNode(head, 3);
    //head = addNode(head, 4);
    //head = addNode(head, 5);

    printList(head);

    removeDuplicates(head);
    printList(head);
}

// Given a singly linked list consisting of N nodes. The task is to remove duplicates (nodes with duplicate values) from the given list (if exists).
// Note: Try not to use extra space. The nodes are arranged in a sorted way.
Node* removeDuplicates(Node* head) {
    Node* cur = head;

    if (head == nullptr)
        return head;

    while (cur->next) {
        // Dup Found
        if (cur->data == cur->next->data) {
            cur->next =cur->next->next;
        } else {
            cur = cur->next;
        }
    }

    return head;
}

Node* addNode(Node* head, int x) {
    Node * current = head; 
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = nullptr;

    // Empty List
    if (head) {
        // Traverse to last node
        while (current->next) {
            current = current->next;
        }

        current->next = newNode;
    } else {
        head = newNode;
    }
    return head;
}

// Delete the node at the x position
// 1 based indexing
Node* deleteNode(Node* head, int x) {
    Node* current = head;
    Node* previous = nullptr;

    // Empty List and single node cases
    if (head == nullptr) {
        return head;
    }

    int i = 1;
    while (i < x) {
        
        // List is too short
        if (current->next == nullptr && i != x) {
            return head;
        }

        // Traverse list
        previous = current;
        current = current->next;
        ++i;
    }

    if (previous) {
        previous->next = current->next;
    } else {
        head = current->next;
    }

    // Deallocate node
    free(current);

    return head;
}

void printList(Node* head) {
    Node* current = head; 
    int value;

    if (current) {
        value = current->data;
        printf("%d -> ", value);        
        while (current->next) {
            current = current->next;
            value = current->data;
            printf("%d -> ", value); 
        }
    }
    printf("null\n");
}