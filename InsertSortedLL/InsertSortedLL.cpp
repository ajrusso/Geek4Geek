/*
Insert in Sorted Linked List

Given a sorted (ascending) linked list of size n, you have to insert the given data at appropriate position in the linked list.

Example 1:

    Input:
    LinkedList: 1->2->3->4->5
    data = 10
    
    Output: 1 2 3 4 5 10

Example 2:

    Input:
    LinkedList: 2->5->7->8->99->100
    data = 100
    
    Output: 2 5 7 8 99 100 100

Your Task:
The task is to complete the function insertInSorted() which takes head reference and data to be inserted as the arguments. The function returns reference to the head node, which is then used to display the list.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= number of nodes <= 103
*/

#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node * next;
    Node (int x)
    {
        data=x;
        next=NULL;
    }
        
};

Node* insertInSorted(Node*, int);


int main() {
    Node* head;
    int data = 5;

    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(6);

    head = insertInSorted(head, data);

    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
}

Node* insertInSorted(Node* head, int data) {
    Node* cur;
    Node* temp;
    
    if(head->data > data) {
        temp = head;
        head = new Node(data);
        head->next = temp;
    } else {
        cur = head;
        while(cur->next) {
            if(cur->next->data > data)
                break;
            cur = cur->next;
        }

        temp = cur->next;
        cur->next = new Node(data);
        cur->next->next = temp;
    }

    return head;
}