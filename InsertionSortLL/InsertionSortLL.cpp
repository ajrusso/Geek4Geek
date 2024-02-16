/*
Insertion Sort for Singly Linked List

Given a singly linked list, sort the list (in ascending order) using insertion sort algorithm.

Example 1:

Input:
N = 10
Linked List = 30->23->28->30->11->14->
              19->16->21->25 
Output : 
11 14 16 19 21 23 25 28 30 30 
Explanation :
The resultant linked list is sorted.
Example 2:

Input : 
N = 7
Linked List=19->20->16->24->12->29->30 
Output : 
12 16 19 20 24 29 30 
Explanation : 
The resultant linked list is sorted.
Your task:
You don't need to read input or print anything. Your task is to complete the function insertionSort() which takes the head of the linked list, sorts the list using insertion sort algorithm and returns the head of the sorted linked list.
 
Expected Time Complexity : O(n2)
Expected Auxiliary Space : O(1)
 
Constraints:
0 <= n <= 5*103
*/


#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* insertionSort(Node*);

int main() {
    int list[] = {30,23,28,30,11,14,19,16,21,25};
    Node* head = NULL;
    Node* tail = NULL;
    Node* result;
    
    for(int i = 0; i < sizeof(list) / sizeof(list[0]); i++) {
        if(head) {
            Node* tmp = new Node(list[i]);
            tail->next = tmp;
            tail = tmp;
        } else {
            head = tail = new Node(list[i]); 
        }
    }

    result = insertionSort(head);

    while(result) {
        printf("%d ", result->data);
        result = result->next;
    }
}

Node* insertionSort(Node* head_ref) {
    Node* cur = head_ref;
    head_ref = new Node(-1);
    Node* prev = head_ref;
    Node* sorted = prev->next;

    while(cur) {
        while(sorted) {
            if(cur->data < sorted->data) {
                prev->next = new Node(cur->data);
                prev->next->next = sorted;
                break;

            } else {
                prev = sorted;
                sorted = sorted->next;
            }
        }

        if(sorted == NULL) {
            prev->next = new Node(cur->data);
        }

        cur = cur->next;
        sorted = head_ref->next;
        prev = head_ref;
    }

    return sorted;
}