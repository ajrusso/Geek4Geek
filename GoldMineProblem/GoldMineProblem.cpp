/*
GOLD MINE PROBLEM

Given a gold mine called M of (n x m) dimensions. Each field in this mine contains a positive integer which is the amount of gold in tons. Initially the miner can start from any row in the first column. From a given cell, the miner can move

to the cell diagonally up towards the right 
to the right
to the cell diagonally down towards the right
Find out maximum amount of gold which he can collect until he can no longer move.

Example 1:

Input: n = 3, m = 3
M = {{1, 3, 3},
     {2, 1, 4},
     {0, 6, 4}};
Output: 12
Explaination: 
The path is {(1,0) -> (2,1) -> (2,2)}.

Example 2:

Input: n = 4, m = 4
M = {{1, 3, 1, 5},
     {2, 2, 4, 1},
     {5, 0, 2, 3},
     {0, 6, 1, 2}};
Output: 16
Explaination: 
The path is {(2,0) -> (3,1) -> (2,2) 
-> (2,3)} or {(2,0) -> (1,1) -> (1,2) 
-> (0,3)}.
Your Task:
You do not need to read input or print anything. Your task is to complete the function maxGold() which takes the values n, m and the mine represented as a 2D array of positive integeres M as input parameters and returns the maximum amount of gold that can be collected.

Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)

Constraints:
1 ≤ n, m ≤ 500
0 ≤ M[i][j] ≤ 100
*/       

#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

int maxGold(int, int, vector<vector<int>>);
int helper(int, int, vector<vector<int>>, int, int, int);

int main() {
    int row = 4;
    int col = 4;
    vector<vector<int>> mine = {{1,3,1,5},
                                {2,2,4,1},
                                {5,0,2,3},
                                {0,6,1,2}};

    int result = maxGold(row, col, mine);

    printf("The maximum amount of gold the miner can collect is %d tons.", result);
}

int maxGold(int row, int col, vector<vector<int>> mine) {
    int tonsGold = 0;
    int maxTonsGold = 0;

    for(int shaft = 0; shaft < row; shaft++) {
        tonsGold = helper(row, col, mine, shaft, 0, 0);
        if(tonsGold > maxTonsGold)
            maxTonsGold = tonsGold;
    }

    return maxTonsGold;
}

int helper(int row, int col, vector<vector<int>> mine, int curRow, int curCol, int curGold) {
    int tonsGold = 0;
    int maxTonsGold = 0;

    if(curCol == col) {
        return curGold;
    } else {
        // Check Up-Diagonal
        if(curRow > 0) {
            tonsGold = helper(row, col, mine, curRow - 1, curCol + 1, curGold + mine[curRow][curCol]);
            if(tonsGold > maxTonsGold)
                maxTonsGold = tonsGold;
        }

        // Check Right
        tonsGold = helper(row, col, mine, curRow, curCol + 1, curGold + mine[curRow][curCol]);
        if(tonsGold > maxTonsGold)
            maxTonsGold = tonsGold;


        // Check Down-Diagonal
        if(curRow != row - 1) {
            tonsGold = helper(row, col, mine, curRow + 1, curCol + 1, curGold + mine[curRow][curCol]);
            if(tonsGold > maxTonsGold)
                maxTonsGold = tonsGold;
        }
        return maxTonsGold;
    }
}