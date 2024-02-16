/*
Merge 2 sorted linked list in reverse order

Given two linked lists of size N and M, which are sorted in non-decreasing order. The task is to merge them in such a way that the resulting list is in non-increasing order.

Example 1:

Input:
N = 2, M = 2
list1 = 1->3
list2 = 2->4
Output:
4->3->2->1
Explanation:
After merging the two lists in non-increasing order, we have new lists as 4->3->2->1.
Example 2:

Input:
N = 4, M = 3
list1 = 5->10->15->40 
list2 = 2->3->20
Output:
40->20->15->10->5->3->2
Explanation:
After merging the two lists in non-increasing order, we have new lists as 40->20->15->10->5->3->2.
Your Task:
The task is to complete the function mergeResult() which takes reference to the heads of both linked list and returns the pointer to the merged linked list.

Expected Time Complexity : O(N+M)
Expected Auxiliary Space : O(1)

Constraints:
0 <= N, M <= 104
*/
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct Node{
    int data;
    Node* next;
};

struct Node* mergeResult(Node*, Node*);
void printList(Node*);


int main() {
    Node* result = NULL;

    // List #1
    Node* list1 = new Node();
    list1->data = 1;
    list1->next = new Node();
    list1->next->data = 3;
    
    // List #2
    Node* list2 = new Node();
    list2->data = 2;
    list2->next = new Node();
    list2->next->data = 4;

    result = mergeResult(list1, list2);

    printf("After merging 2 lists in non-increasing order, we have new lists....\n");
    
    printList(result);
}

Node* mergeResult(Node* node1, Node* node2) {
    Node* result = NULL;
    Node* tmp;
    int least;    

    while(node1 && node2) {
        
        if(node1->data <= node2->data) {
            least = node1->data;
            node1 = node1->next;
        } else {
            least = node2->data;
            node2 = node2->next;
        }

        if(result) {
            tmp = result;
            result = new Node();
            result->data = least;

            result->next = tmp;
        } else {
            result = new Node();
            result->data = least;
        }
    }

    while(node1) {
        tmp = result;
        result = new Node();
        result->data = node1->data;
        result->next = tmp;
        node1 = node1->next;
    }

    while(node2) {
        tmp = result;
        result = new Node();
        result->data = node2->data;
        result->next = tmp;
        node2 = node2->next;
    }
    
    return result;
}

void printList(Node* list) {
    if(list) {
        while(list->next) {
            printf("%d->", list->data);
            list = list->next;
        }
        printf("%d\n", list->data);
    }
}