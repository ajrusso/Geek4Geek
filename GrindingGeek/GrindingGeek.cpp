/*
Grinding Geek

GeeksforGeeks has introduced a special offer where you can enroll in any course, and if you manage to complete 90% of the course within 90 days, you will receive a refund of 90%.

Geek was fascinated by this offer. This offer was valid for only n days, and each day a new course was available for purchase. Geek decided that if he bought a course on some day, he will complete that course on the same day itself and redeem floor[90% of cost of the course] amount back. Find the maximum number of courses that Geek can complete in those n days if he had total amount initially.

Note: On any day, Geek can only buy the new course that was made available for purchase that day.

Example 1:

Input:
n = 2
total = 10
cost = [10, 9]
Output: 2
Explanation: 
Geek can buy the first course for 10 amount, 
complete it on the same date and redeem 9 back. 
Next, he can buy and complete the 2nd course too.
Example 2:

Input:
n = 11
total = 10
cost = [10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
Output: 10
Explanation: 
Geek can buy and complete all the courses that cost 1.
Your Task:
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function max_courses() that takes N the number of days, the total amount, and the cost array as input argument and return the maximum amount of courses that could be purchased.

Expected Time Complexity: O(n*total)
Expected Auxiliary Space: O(n*total)

Constraints:
1 <= n <= 1000
0 <= total <= 1000
1 <= cost[i] <= 1000
*/

#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

int max_courses(int, int, vector<int> );

int main() {
    int n = 2;
    int total = 10;
    vector<int> cost = {10,9};
    int result;

    result max_courses(n, total, cost);

    printf("Geek can buy and complete %d course(s)", result);
}

int max_courses(int n, int total, vector<int> &cost) {
    int result = 0;

    return result;
}