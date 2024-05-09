#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;
// Function to perform DFS traversal on the graph and record finishing times
void dfs(vector<vector<int>>& graph, int v, vector<bool>& visited, stack<int>& finishedStack) {
    visited[v] = true;
    // Traverse adjacent vertices of v
    for (int neighbor : graph[v]) {
        if (!visited[neighbor]) {
            dfs(graph, neighbor, visited, finishedStack);  } }
    // Push vertex v to the stack after all its adjacent vertices are visited
    finishedStack.push(v);}
// Function perform DFS traversal on the transposed graph and identify strongly connected components
void dfsTranspose(vector<vector<int>>& transposeGraph, int v, vector<bool>& visited, vector<int>& scc, int sccId) {
    visited[v] = true;
    scc[v] = sccId; // Assign the SCC ID to the vertex
    // Traverse adjacent vertices of v in the transposed graph
    for (int neighbor : transposeGraph[v]) {
        if (!visited[neighbor]) {
            dfsTranspose(transposeGraph, neighbor, visited, scc, sccId);      }}}
// Function  find all strongly connected components in directed graph
vector<vector<int>> findStronglyConnectedComponents(vector<vector<int>>& graph) {
    int n = graph.size(); // Number of vertices in the graph
    vector<bool> visited(n, false); // Array to mark visited vertices
    stack<int> finishedStack; // Stack to store finishing times of vertices
    vector<vector<int>> transposeGraph(n); // Transposed graph
    vector<int> scc(n, -1); // Array to store SCC IDs
    int sccId = 0; // SCC ID counter
    // Perform DFS traversal on the original graph and record finishing times
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(graph, i, visited, finishedStack);  }}
    //  (reverse the direction of all edges) Transpose the graph
    for (int u = 0; u < n; ++u) {
        for (int v : graph[u]) {
            transposeGraph[v].push_back(u);  } }
    // Reset visited array for DFS on the transposed graph
    fill(visited.begin(), visited.end(), false);
    // Perform DFS traversal on the transposed graph in the order of decreasing finishing times
    while (!finishedStack.empty()) {
        int v = finishedStack.top();
        finishedStack.pop();
        if (!visited[v]) {
            dfsTranspose(transposeGraph, v, visited, scc, sccId);
            ++sccId;}}
    // Collect vertices of  strongly connected component
    vector<vector<int>> stronglyConnectedComponents(sccId);
    for (int i = 0; i < n; ++i) {
        stronglyConnectedComponents[scc[i]].push_back(i);}
    return stronglyConnectedComponents;}
int main() {
    // Example directed graph represented as an adjacency list
    vector<vector<int>> graph = {{1, 2},{2, 3},{0, 4},{5},{3}, {4, 6}, {7},   {5}  };// Adjacent vertices of vertex {0-7}
    // Find all strongly connected components in the graph
    vector<vector<int>> stronglyConnectedComponents = findStronglyConnectedComponents(graph);
    //output
    cout << "Strongly Connected Components:" << endl;
    for (const auto& component : stronglyConnectedComponents) {
        cout << "Component: ";
        for (int vertex : component) {
            cout << vertex << " ";
        }cout << endl;}
    return 0;}
