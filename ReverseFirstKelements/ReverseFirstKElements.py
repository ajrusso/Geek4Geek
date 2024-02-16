'''
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
'''
from queue import LifoQueue


def main():
    q = [1,2,3,4,5]
    k = 3

    result = modifyQueue(q, k)
    print(result)
    
def modifyQueue(q, k):
    stack = LifoQueue()
    result = []
    
    # Store k elements of q in a stack
    while(k):
        stack.put(q.pop(0))
        k -= 1
        
    # Add k elements back to result queue in reverse order
    while(not stack.empty()):
        result.append(stack.get_nowait())

    # Add the remaining q elements to the result
    while(q):
        result.append(q.pop(0))

    return result
        
if __name__ == "__main__":
    main()