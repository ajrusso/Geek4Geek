#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

Node* reverseDLL(Node*);

int main() {
    Node* head = new Node(3);
    Node* result;
    
    head->next = new Node(4);
    head->next->prev = head;
    head->next->next = new Node(5);
    head->next->next->prev = head->next;

    result = reverseDLL(head);

    while(result) {
        printf("%d ", result->data);
        result = result->next;
    }
}

Node* reverseDLL(Node* head) {
    static Node* result = NULL;
    Node* tmpPrev;
    Node* tmpNext;

    while(head) {
        result = head;
        tmpPrev = head->prev;
        tmpNext = head->next;
        result->next = tmpPrev; 
        result->prev = tmpNext;
        result = result->prev;
        head = head->next;
    }

    return result;
}