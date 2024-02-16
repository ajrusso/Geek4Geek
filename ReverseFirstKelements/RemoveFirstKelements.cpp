/*
Reverse First K elements of Queue

Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue, leaving the other elements in the same relative order.

Only following standard operations are allowed on queue.

enqueue(x) : Add an item x to rear of queue
dequeue() : Remove an item from front of queue
size() : Returns number of elements in queue.
front() : Finds front item.
Note: The above operations represent the general processings. In-built functions of the respective languages can be used to solve the problem.

Example 1:

Input:
5 3
1 2 3 4 5
Output: 
3 2 1 4 5
Explanation: 
After reversing the given
input from the 3rd position the resultant
output will be 3 2 1 4 5.
Example 2:

Input:
4 4
4 3 2 1
Output: 
1 2 3 4
Explanation: 
After reversing the given
input from the 4th position the resultant
output will be 1 2 3 4.
Your Task:
Complete the provided function modifyQueue() that takes queue and K as parameters and returns a modified queue. The printing is done automatically by the driver code.

Expected Time Complexity : O(N)
Expected Auxiliary Space : O(K)

Constraints:
1 <= K <= N <= 105
*/

#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <stack>

using namespace std;

queue<int> modifyQueue(queue<int>, int);

int main() {
    queue<int> q;
    queue<int> res;
    int k = 3;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    res = modifyQueue(q, k);

    while(!res.empty()) {
        printf("%d ", res.front());
        res.pop();
    }
}

queue<int> modifyQueue(queue<int> q, int k) {
    stack<int> st;
    queue<int> result;

    // Store k elements of q in a stack
    while(k--) {
        st.push(q.front());
        q.pop();
    }

    // Add k elements back to result queue in reverse order 
    while(!st.empty()) {
        result.push(st.top());
        st.pop();
    }

    // Add the remaining q elements to the result
    while(!q.empty()) {
        result.push(q.front());
        q.pop();
    }

    return result; 
}