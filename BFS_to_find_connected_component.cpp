#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
// Function  BFS and find all connected components in graph
vector<vector<int>> findConnectedComponents(vector<vector<int>>& graph) {
    int n = graph.size(); // Number of vertices in the graph
    vector<bool> visited(n, false); // Array to mark visited vertices
    vector<vector<int>> connectedComponents; // Vector of vectors to store connected components
    // Perform BFS starting from each vertex
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            vector<int> component; // Vector to store vertices in the current connected component
            queue<int> q; // Queue for BFS traversal
            // Enqueue the current vertex and mark it as visited
            q.push(i);
            visited[i] = true;
            // Perform BFS
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                component.push_back(u); // Add vertex to the current connected component
                // Traverse adjacent vertices of u
                for (int v : graph[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v); }}}
            // Add the current connected component to the vector of connected components
            connectedComponents.push_back(component); }}
    return connectedComponents;}
int main() {
    // Example graph represented as an adjacency list
    vector<vector<int>> graph = {
        {1, 2}, {0, 3},{0, 4},  {1}, {2},{6},{5}}; //adjecent vertice form {0-6}
    // Find all connected components in the graph
    vector<vector<int>> connectedComponents = findConnectedComponents(graph);
    // Output vertices within each connected component
    cout << "Connected Components:" << endl;
    for (const auto& component : connectedComponents) {
        cout << "Component: ";
        for (int vertex : component) {
            cout << vertex << " ";   }   cout << endl; }
    return 0;}
