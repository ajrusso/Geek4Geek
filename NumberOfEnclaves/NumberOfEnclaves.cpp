#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;


int numberOfEnclaves(vector<vector<int>> &);
int numberOfEnclavesRec(vector<vector<int>> &grid, int m, int n, int i, int j);
void printGrid(vector<vector<int>>);


int main()
{
    vector<vector<int>> grid = {{0,1,1,0},
                                {0,0,1,0},
                                {0,0,1,0},
                                {0,0,0,0}};
    int numEnclaves;

    printGrid(grid);
    numEnclaves = numberOfEnclaves(grid);
    printGrid(grid);

    printf("Number of Enclaves is %d\n", numEnclaves);
}

int numberOfEnclaves(vector<vector<int>> & grid)
{
    int maxEnclaves = 0;
    int enclaves = 0;
    int m = grid.size();
    int n = grid[0].size();

    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(grid[i][j] > 0)
            {
                enclaves = numberOfEnclavesRec(grid, m, n, i, j);

                if(enclaves > maxEnclaves)
                    maxEnclaves = enclaves;
            }
        }
    }

    return maxEnclaves;
}

int numberOfEnclavesRec(vector<vector<int>> &grid, int m, int n, int i, int j)
// To Do: Add check for edges. A move consists of walking from one land cell or
//        walking off the boundary of the grid.
{
    int count = 0;
    
    if(grid[i][j] < 1)
    {
        return 0;
    }
    else
    {
        ++count;
        grid[i][j] = -1;
        // check right
        if(j < n - 1)
        {
            if(grid[i][j + 1] > 0)
            {
                count += numberOfEnclavesRec(grid, m, n, i, j + 1);
            } 
        }

        // check left 
        if(j >= 1 )
        {
            if(grid[i][j - 1] > 0)
            {
                count += numberOfEnclavesRec(grid, m, n, i, j - 1);
            } 
        }

        // check below
        if(i < m - 1)
        {
            if(grid[i + 1][j] > 0)
            {
                count += numberOfEnclavesRec(grid, m, n, i + 1, j);
            }
        }

        // check up
        if(i >= 1)
        {
            if(grid[i - 1][j] > 0)
            {
                count += numberOfEnclavesRec(grid, m, n, i - 1, j);
            }
        }
    }
    return count;
}

void printGrid(vector<vector<int>> grid) 
{
    for(int i = 0; i < grid.size(); ++i)
    {
        for(int j = 0; j < grid[0].size(); ++j)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}