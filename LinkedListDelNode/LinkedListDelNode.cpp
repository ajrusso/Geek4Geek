#include <stdio.h>
#include <stdlib.h>


using namespace std;


struct Node {
    int data;
    Node* next;
};


Node* addNode(Node*, int);
Node* deleteNode(Node*, int);
Node* compute(Node*);
Node* computeRecursive(Node*);
void printList(Node*);


int main() {
    Node* head = nullptr;

    head = addNode(head, 9);
    head = addNode(head, 3);
    head = addNode(head, 2);
    head = addNode(head, 6);
    head = addNode(head, 7);
    head = addNode(head, 2);
    head = addNode(head, 4);
    head = addNode(head, 10);
    head = addNode(head, 1);
    head = addNode(head, 5);
    printList(head);

    head = computeRecursive(head);
    printList(head);
}

Node* compute(Node* head) {
    Node* cur = head;
    Node* prev = NULL;

    if (head == NULL)
        return head;
    
    while (cur->next) {
        if (cur->data < cur->next->data) {
            if (prev ) {
                prev->next = cur->next;
                cur = cur->next;
            } else {
                head = head->next;
                cur = head;
            }
        } else {
            prev = cur;
            cur = cur->next;
        }
    }

    return head;
}

Node* computeRecursive(Node* head) {
    Node* cur;

    if (head->next == NULL) {
        return head;
    } else {
        cur = computeRecursive(head->next);
        head->next = cur;
        if (head->data < cur->data) {
            return cur;
        } else {
            return head;
        }
    }
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