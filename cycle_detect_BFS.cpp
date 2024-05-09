#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

// Function to check  cycle in an undirected graph using BFS
bool hasCycle(vector<vector<int>>& graph) {
    int n = graph.size(); // Number of vertices in the graph
    vector<bool> visited(n, false); // Array to mark visited vertices
    queue<int> q; // Queue for BFS traversal
    // Perform BFS starting from each vertex
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            q.push(i);
            visited[i] = true;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                // Traverse adjacent vertices of u
                for (int v : graph[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    } else {
                        // If v is already visited and not the parent of u, there is a cycle
                        if (v != u) {
                            return true;  } } } }  }}
  return false;} // No cycle found
  

int main() {
    // Example graph  as  adjacency list
    vector<vector<int>> graph = {
        {1, 2},  {0, 3}, {0, 4}, {1}, {}};//adjecent vertice {0-6}

    if (hasCycle(graph)) {
        cout << "The graph contains a cycle." << endl;
    } else {
        cout << "The graph does not contain a cycle." << endl;
    }

    return 0;
}
