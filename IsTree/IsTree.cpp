/*
Is it a Tree?

You are given an undirected graph of N nodes and M edges. Return 1 if the graph is a tree, else return 0.

Note: The input graph can have self-loops and multiple edges.

Example 1:

Input:
N = 4, M = 3
G = [[0, 1], [1, 2], [1, 3]]
Output: 
1
Explanation: 
Every node is reachable and the graph has no loops, so it is a tree
Example 2:

Input:
N = 4, M = 3
G = [[0, 1], [1, 2], [2, 0]]
Output: 
0
Explanation: 
3 is not connected to any node and there is a loop 0->1->2->0, so it is not a tree.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function isTree() which takes the integer N (the number nodes in the input graph) and the edges representing the graph as input parameters and returns 1 if the input graph is a tree, else 0.

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(N)

Constraints:
1 <= N <= 2*105
0 <= M <= 2*105
*/
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int isTree(int, int, vector<vector<int>>&);
int isTree2(int, int, vector<vector<int>>&);
int isCyclic(int, int, vector<vector<int>>, vector<int>);

int main() {
    int n = 4;
    int m = 3;
    vector<vector<int>> adj = {{0,1},{1,2},{1,3}};

    int result = isTree(n, m, adj);

    printf("%d", result);
}

int isTree(int n, int m, vector<vector<int>>& adj) {
    vector<vector<int>> adjacent(n);
    for(auto node : adj) {
        adjacent[node[0]].push_back(node[1]);
        adjacent[node[1]].push_back(node[0]);
    }

    vector<int> visited(n,0);
    queue<pair<int, int>> q;
    q.push({0,-1});
    visited[0] = 1;
    while(!q.empty()) {
        auto temp = q.front();
        q.pop();
        
        for(int node : adjacent[temp.first]) {
            if(!visited[node]) {
                visited[node] = 1;
                q.push({node, temp.first});
            } else {
                if(node != temp.second)
                    return 0;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(!visited[i])
            return 0;
    }
    return 1;
}

int isTree2(int n, int m, vector<vector<int>>& adj) {
    if(n - m != 1)
        return 0;
    
    vector<vector<int>> adjacent(n);
    for(int i = 0; i < m; i++) {
        adjacent[adj[i][0]].push_back(adj[i][1]);
        adjacent[adj[i][1]].push_back(adj[i][0]);
    }

    vector<int> visited(n,0);
    if(isCyclic(0, -1, adjacent, visited)) 
        return 0;
    
    for(int i = 0; i < n; i++) {
        if(!visited[i])
            return 0;
    }
    return 1;  
}

int isCyclic(int n, int parent, vector<vector<int>> adj, vector<int> visited) {
    visited[n] = 1;
    for(int node : adj[n]) {
        if(!visited[node]) {
            if(isCyclic(node, n, adj, visited))
                return 1;
        } else if (node != parent) {
            return 1;
        }
    }
    return 0;
}