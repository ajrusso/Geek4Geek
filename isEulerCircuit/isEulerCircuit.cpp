/*
An Eulerian Path is a path in graph that visits every edge exactly once and it starts and ends up at different indexes. An Eulerian Circuit is an Eulerian Path which starts and ends on the same vertex. Given an undirected acyclic graph with V nodes, and E edges, with adjacency list adj, return 2 if the graph contains an eulerian circuit, else if the graph contains an eulerian path, return 1, otherwise, return 0.

Example 1:

Input: 
V = 3
adj = {{1,2},{2,0},{0,1}}
Output: 2
Explanation:
Following is an eulerian circuit in the mentioned graph
1 -> 2 -> 0 -> 1
Example 2:

Input: 
V = 3
adj = {{1,0},{0,2}}
Output: 1
Explanation: 
Following is an eulerian circuit in the mentioned graph
1 -> 0 -> 2
Your Task:
You don't need to read or print anything. Your task is to complete the function isEulerCircuilt() which takes number of vertices in the graph denoted as V and an adjacency list of graph denoted as adj and returns 2 if the graph contains an eulerian circuit, else if the graph contains an eulerian path, it returns 1, otherwise, it will return 0.

Expected Time Complexity: O(V+E) where E is the number of edges in graph.
Expected Space Complexity: O(V)

Constraints:
1 ≤ V, E ≤ 104
1 ≤ adj[i][j] ≤ V-1
*/

#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

#define EULERIAN_CURCUIT 2
#define EULERIAN_PATH 1
#define NO_EULERIAN_PATH_OR_CURCUIT_FOUND 0

int isEulerCircuit(int, vector<int>[]);

int main() {
    int V = 3;
    vector<int> adj[] = {{0,1},{0,2},{1,2}};
    int result;

    result = isEulerCircuit(V, adj);

    switch(result) {
        case EULERIAN_CURCUIT:
            printf("Eulerian Curcuit Found");
            break;
        case EULERIAN_PATH:
            printf("Eulerian Path Found");
            break;
        case NO_EULERIAN_PATH_OR_CURCUIT_FOUND:
            printf("No Eulerian Path or Curcuit Found");
            break;
        default:
            printf("Error: Improper Result returned");
    }
}

int isEulerCircuit(int V, vector<int>adj[]) {
    vector<int> nodeDegree(V,0);
    int odd = 0;
    int even = 0;

    for(int i = 0; i < V; i++) {
        for(int j : adj[i]) {
            nodeDegree[j]++;
        }
    }

    for(int degree : nodeDegree) {
        if(degree % 2 == 0)
            even++;
        else
            odd++;
    }

    if(even == V)
        return EULERIAN_CURCUIT;
    else if(odd <= 2)
        return EULERIAN_PATH;
    else
        return NO_EULERIAN_PATH_OR_CURCUIT_FOUND;
}