#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
#define INF INT_MAX
// Structure to represent an edge
struct Edge
{
    int dest;   // Destination vertex
    int weight; // Weight
};
// Function to find shortest paths from a given source vertex using djks's algorithm
void djks(vector<vector<Edge>> &graph, int source)
{
    int V = graph.size();
    vector<int> dist(V, INF);
    vector<bool> visited(V, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap
    dist[source] = 0;                                                                   // source distance
    // Insert source vertex into priority queue
    pq.push({0, source});
    // djks's algorithm
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        // Skip processing if the vertex is visited
        if (visited[u])
            continue;
        // Mark vertex as visited
        visited[u] = true;
        // Update distances of adjacent vertices
        for (Edge &edge : graph[u])
        {
            int v = edge.dest;
            int weight = edge.weight;
            // Relaxation step
            if (dist[u] != INF && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    // Print shortest distances from source vertex to all other vertices
    cout << "Shortest distances from vertex " << source << ":\n";
    for (int i = 0; i < V; ++i)
    {
        if (dist[i] == INF)
            cout << "Vertex " << i << ": Not reachable\n";
        else
            cout << "Vertex " << i << ": " << dist[i] << endl;
    }
}
int main()
{

    vector<vector<Edge>> graph = {
        {{1, 3}, {2, 6}, {3, 8}},
        {{4, 2}, {5, 5}, {6, 4}},
        {{7, 9}},
        {{8, 7}, {9, 3}},
        {{10, 1}},
        {{11, 5}},
        {{10, 4}},
        {{11, 2}},
        {{}} ,{{}}, {{}}, {{}}};

    int source = 0; 
    djks(graph, source); //function call 

    return 0;
}
