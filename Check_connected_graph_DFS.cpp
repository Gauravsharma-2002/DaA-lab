#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
// DFS function to traverse 
void dfs(vector<vector<int>>& graph, int v, vector<bool>& visited) {
    visited[v] = true;
    // Traverse adjacent vertices of v
    for (int neighbor : graph[v]) {
        if (!visited[neighbor]) {
            dfs(graph, neighbor, visited);}}}
// Function to check  graph is connected using DFS
bool isConnected(vector<vector<int>>& graph) {
    int n = graph.size(); // Number of vertices in the graph
    vector<bool> visited(n, false); // Array to mark visited vertices
    // Perform DFS from vertex 0
    dfs(graph, 0, visited);
    // Check for visited vertices
    for (bool v : visited) {
        if (!v) {
            return false;}} // If any vertex is not visited, the graph is not connected
    return true;} // If all vertices are visited, the graph is connected


int main() {
    // Example undirected graph represented as an adjacency list
    vector<vector<int>> graph = { {1, 2}, {0, 3}, {0, 4}, {1}, {2} }; // Adjacent vertices of vertex {0-4}

    if (isConnected(graph)) {cout << "The graph is connected." << endl;} 
    else { cout << "The graph is not connected." << endl; }
    return 0;}
