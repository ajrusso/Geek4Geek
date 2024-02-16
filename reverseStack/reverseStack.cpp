#include <stack>
#include <stdio.h>
using namespace std;

void Reverse(stack<int> &St);
void PushBottom(stack<int> &St, int);
void Print(stack<int> St);

int main() {
    stack<int> St;
    int size;

    St.emplace(1);
    St.emplace(2);
    St.emplace(3);
    St.emplace(4);
    St.emplace(5);

    printf("OG Stack\n");
    Print(St);

    Reverse(St);
    printf("Reverse Stack\n");
    Print(St);

}

// function to reverse a stack recursively 
void Reverse(stack<int> &St) {
    if (St.empty()) {
        return;
    } else {
        int top = St.top();
        St.pop();
        Reverse(St);
        PushBottom(St, top);
    }
}

// Push element to bottom of the stack
void PushBottom(stack<int> &St, int element) {
    
    if (St.empty()) {
        St.push(element);
    } else {
        int top = St.top();
        St.pop();
        PushBottom(St, element);
        St.push(top);
    }
}

// Print Stack
void Print(stack<int> St) {    
    while (!St.empty()) {
        printf("%d\n", St.top());
        St.pop();
    }
    printf("\n");
}