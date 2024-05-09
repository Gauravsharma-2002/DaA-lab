#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// BFS function
void shortestPaths(vector<vector<int>> &graph, int source)
{
    int n = graph.size();        // Number of verticesin the graph
    vector<int> distance(n, -1); // Array to store distances from the source vertex
    vector<int> parent(n, -1);   // Array to store parent vertices for constructing shortest paths

    // Queue for BFS traversal
    queue<int> q;

    // Enqueue the source vertex and mark it as visited
    q.push(source);
    distance[source] = 0;

    // Perform BFS
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        // Traverse adjacent vertices of u
        for (int v : graph[u])
        {
            if (distance[v] == -1)
            {                                  // If v is not visited yet
                distance[v] = distance[u] + 1; // Update distance to v
                parent[v] = u;                 // Update parent of v
                q.push(v);                     // Enqueue v for further traversal
            }
        }
    }

    // Output shortest paths from source to all vertices
    for (int i = 0; i < n; ++i)
    {
        cout << "Shortest path from " << source << " to " << i << ": ";
        if (distance[i] == -1)
        {
            cout << "No path exists" << endl;
        }
        else
        {
            vector<int> path;
            int current = i;
            while (current != -1)
            {
                path.push_back(current);
                current = parent[current];
            }
            cout << source;
            for (int j = path.size() - 2; j >= 0; --j)
            {
                cout << " -> " << path[j];
            }
            cout << ", Distance: " << distance[i] << endl;
        }
    }
}

int main()
{
    // Example graph  adjacency list
    vector<vector<int>> graph = {{1, 2}, {0, 3, 4}, {0, 4}, {1}, {1, 2}}; // Adjacent vertices of vertex {0-4}

    int source = 0; // Source vertex to find shortest paths from
    shortestPaths(graph, source);

    return 0;
}
