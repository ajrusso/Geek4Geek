/*
Print Matrix in Diagonal Pattern

Given a square matrix mat[][] of n*n size, the task is to determine the order of its elements in a
 diagonal pattern as depicted below.

Example 1:

    Input:
     n = 3
     mat[][] = {{1, 2, 3},
             {4, 5, 6},
             {7, 8, 9}}
    
    Output: {1, 2, 4, 7, 5, 3, 6, 8, 9}
    
    Explaination:
     Starting from (0, 0): 1,
     Move to the right to (0, 1): 2,
     Move diagonally down to (1, 0): 4,
     Move diagonally down to (2, 0): 7,
     Move diagonally up to (1, 1): 5,
     Move diagonally up to (1, 2): 3,
     Move to the right to (2, 1): 6,
     Move diagonally up to (0, 2): 8,
     Move diagonally up to (2, 2): 9
     There for the output is {1, 2, 4, 7, 5, 3, 6, 8, 9}.

Example 2:

    Input:
     n = 2
     mat[][] = {{1, 2},
             {3, 4}}
    
    Output: {1, 2, 3, 4}
    
    Explaination:
     Starting from (0, 0): 1,
     Move to the right to (0, 1): 2,
     Move diagonally down to (1, 0): 3,
     Move to the right to (1, 1): 4
     There for the output is {1, 2, 3, 4}.

Your Task:
 You only need to implement the given function matrixDiagonally() which takes a matrix mat[][] of
 size n*n as an input and returns a list of integers containing the matrix diagonally. Do not read
 input, instead use the arguments given in the function.

Expected Time Complexity: O(n*n).
Expected Auxiliary Space: O(1).

Constraints:
 1 <= n <= 100
 -100 <= elements of matrix <= 100
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> matrixDiagonally(vector<vector<int>>&);

int main() {
    vector<vector<int>> mat = {{1,2},
                               {3,4}};

    vector<int> result = matrixDiagonally(mat);

    cout << "{";
    for(int i = 0; i < result.size() - 1; i++)
        cout << result[i] << ", ";
    cout << result[result.size() - 1] << "}" << endl;  
}

vector<int> matrixDiagonally(vector<vector<int>> &mat) {
    vector<int> result = {};
    int n = mat[0].size();
    int x = 0;
    int y = 0;
    bool diagUpR = true;
    
    result.push_back(mat[0][0]);
    while(&mat[x][y] != &mat[n - 1][n - 1]) {
        
        if(diagUpR) {
            if(y < n - 1) {
                y++;
                if(x > 0) {
                   x--;
                } else {
                    diagUpR = false;
                }
            } else {
                x++;
                diagUpR = false;
            }
        } else {
            if(x < n - 1) {
                x++;
                if(y > 0) {
                    y--;
                } else {
                    diagUpR = true;
                }
            } else {
                y++;
                diagUpR = true;
            }
        }
        result.push_back(mat[x][y]);
    }
    return result;
}