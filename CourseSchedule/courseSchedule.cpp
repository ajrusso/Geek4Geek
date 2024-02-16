/*
Course Schedule

There are a total of n tasks you have to pick, labelled from 0 to n-1. Some tasks may have prerequisite tasks, for example to pick task 0 you have to first finish tasks 1, which is expressed as a pair: [0, 1]
Given the total number of n tasks and a list of prerequisite pairs of size m. Find a ordering of tasks you should pick to finish all tasks.
Note: There may be multiple correct orders, you just need to return any one of them. If it is impossible to finish all tasks, return an empty array. Driver code will print "No Ordering Possible", on returning an empty array. Returning any correct order will give the output as 1, whereas any invalid order will give the output 0. 

Example 1:

Input:
n = 2, m = 1
prerequisites = {{1, 0}}
Output:
1
Explanation:
The output 1 denotes that the order is valid. So, if you have, implemented your function correctly, then output would be 1 for all test cases. One possible order is [0, 1].
Example 2:

Input:
n = 4, m = 4
prerequisites = {{1, 0},
               {2, 0},
               {3, 1},
               {3, 2}}
Output:
1
Explanation:
There are a total of 4 tasks to pick. To pick task 3 you should have finished both tasks 1 and 2. Both tasks 1 and 2 should be pick after you finished task 0. So one correct task order is [0, 1, 2, 3]. Another correct ordering is [0, 2, 1, 3]. Returning any of these order will result in an output of 1.
Your Task:
The task is to complete the function findOrder() which takes two integers n, and m and a list of lists of size m*2 denoting the prerequisite pairs as input and returns any correct order to finish all the tasks. Return an empty array if it's impossible to finish all tasks.

Expected Time Complexity: O(n+m).
Expected Auxiliary Space: O(n+m).
 
Constraints:
1 ≤ n ≤ 105
0 ≤ m ≤ min(n*(n-1),105)
0 ≤ prerequisites[i][0], prerequisites[i][1] < n
All prerequisite pairs are unique
prerequisites[i][0] ≠ prerequisites[i][1]
*/
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

vector<int> findOrder(int, int, vector<vector<int>>);

int main() {
    int n = 43;
    int m = 28;
    vector<vector<int>> prerequisites = {{27,6},{40,28},{15,2},{16,28},{16,11},{16,5},{23,0},{14,2},{17,28},{12,32},{13,19},{40,30},{42,22},{35,42},{25,10},{3,39},{10,21},{33,4},{21,30},{33,9},{5,11},{40,5},{40,8},{38,40},{6,23},{11,18},{5,14},{41,19}};
    vector<int> order = {};

    vector<int> result = findOrder(n, m, prerequisites);

    if(!result.empty())
        for(int i : result)
            printf("%d ", result[i]);
    else
        printf("No Ordering Possible");
}


// Kahn's algorithm for Topological Sorting
// https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/
vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) {
    vector<int> order = {};
    vector<int> prereq_count(n, 0);
    vector<vector<int>> prereq_list(n); 
    queue<int> q;

    // Build task prereq list (in order) and prereq count list
    for(auto prereq : prerequisites) {
        prereq_list[prereq[1]].push_back(prereq[0]);
        prereq_count[prereq[0]]++;
    }

    // Add any tasks with zero prerequisites to the front of the queue
    for(int i = 0; i < prereq_count.size(); i++) {
        if(prereq_count[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int task = q.front();
        q.pop();
        order.push_back(task);

        for(auto prereq : prereq_list[task]) {
            prereq_count[prereq]--;
            if(prereq_count[prereq] == 0)
                q.push(prereq);
        }
    }

    if(order.size() != n)
        order = {};

    return order;
}