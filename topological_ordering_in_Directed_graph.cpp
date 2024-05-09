#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;
void dfsTopological(vector<vector<int>>& graph, int v, vector<bool>& visited, stack<int>& orderStack) {
    visited[v] = true;
    for (int neighbor : graph[v]) {
        if (!visited[neighbor]) {
            dfsTopological(graph, neighbor, visited, orderStack);  } }
    orderStack.push(v);}
vector<int> topologicalSort(vector<vector<int>>& graph) {
    int n = graph.size(); 
    vector<bool> visited(n, false); 
    stack<int> orderStack; 
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfsTopological(graph, i, visited, orderStack);}}
    vector<int> topologicalOrder;
    while (!orderStack.empty()) {
        topologicalOrder.push_back(orderStack.top());
        orderStack.pop(); }
    return topologicalOrder;}
int main() {
    vector<vector<int>> graph = {{1, 2},{3, 4},{5},{4},{5},{6},{7},{}}; // Adjacent vertices of vertex {0-7}
    vector<int> topologicalOrder = topologicalSort(graph);
    cout << "Topological Ordering of Vertices:" << endl;
    for (int vertex : topologicalOrder) {
        cout << vertex << " "; }
    cout << endl;
    return 0;}
