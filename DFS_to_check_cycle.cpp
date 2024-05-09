#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
// DFS function to check  cycle
bool hasCycleDFS(vector<vector<int>>& graph, int v, vector<bool>& visited, vector<bool>& recStack) {
    visited[v] = true;
    recStack[v] = true;
    // Traverse adjacent vertices of v
    for (int neighbor : graph[v]) {
        if (!visited[neighbor]) {
            if (hasCycleDFS(graph, neighbor, visited, recStack))
                return true;
        } else if (recStack[neighbor]) {
            // If neighbor is visited and in the recursion stack, there is a cycle
            return true;}}
    // Remove vertex v from  recursion stack
    recStack[v] = false;
    return false;}
// Function to check  cycle in  directed graph 
bool hasCycle(vector<vector<int>>& graph) {
    int n = graph.size(); // Number of vertices in the graph
    vector<bool> visited(n, false); // Array to mark visited vertices
    vector<bool> recStack(n, false); // Array to mark vertices in the recursion stack
    // Perform DFS from each vertex
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            if (hasCycleDFS(graph, i, visited, recStack))
                return true;}}
    return false; }// No cycle found
int main() {
    // Example directed graph as adjacency list
    vector<vector<int>> graph = {  {1, 2}, {2},  {3}, {0} }; // Adjacent vertices of vertex {0-3}
    if (hasCycle(graph)) {cout << "The graph contains a cycle." << endl;} 
    else { cout << "The graph does not contain a cycle." << endl;}
    return 0;}
