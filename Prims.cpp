#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
struct Edge
{
    int dest, weight;
};
void Prim(vector<vector<Edge>> &graph, int V)
{
    // store vertices and their distances in pq
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // set visited vertices
    vector<bool> visited(V, false);
    // Add starting vertex to MST
    pq.push({0, 0}); // Distance, Vertex
    int minCost = 0; // Minimum cost of MST
    // Prim's algorithm
    while (!pq.empty())
    {
        int u = pq.top().second;
        int dist = pq.top().first;
        pq.pop();
        // Skip if vertex is already visited
        if (visited[u])
            continue;
        // Mark vertex as visited
        visited[u] = true;
        // Add edge weight to MST cost
        minCost += dist;
        // Add adjacent vertices to priority queue
        for (Edge &edge : graph[u])
        {
            int v = edge.dest;
            int weight = edge.weight;
            if (!visited[v])
            {
                pq.push({weight, v});
            }
        }
    }

    cout << "Minimum Spanning Tree (MST) cost: " << minCost << endl;
}
int main()
{

    vector<vector<Edge>> graph = {
        {{1, 4}, {2, 8}, {3, 10}, {4, 6}, {5, 2}, {6, 7}, {7, 9}, {8, 3}, {9, 5}, {10, 11}},
        {{0, 4}, {2, 3}, {4, 9}, {9, 8}, {10, 6}},
        {{0, 8}, {1, 3}, {4, 7}, {6, 5}, {7, 4}, {8, 1}},
        {{0, 10}, {7, 6}, {11, 8}, {15, 7}},
        {{0, 6}, {1, 9}, {2, 7}, {8, 2}, {13, 5}, {14, 6}},
        {{0, 2}, {9, 3}, {11, 4}, {16, 5}},
        {{0, 7}, {2, 5}, {13, 9}, {17, 7}, {18, 3}},
        {{0, 9}, {3, 6}, {6, 4}, {10, 7}, {17, 8}, {19, 2}},
        {{0, 3}, {2, 1}, {4, 2}, {10, 4}, {11, 6}, {18, 5}},
        {{0, 5}, {5, 3}, {7, 7}, {14, 9}, {16, 8}, {20, 4}, {21, 3}},
        {{0, 11}, {1, 6}, {7, 7}, {8, 4}, {12, 8}, {22, 5}},
        {{3, 8}, {5, 4}, {9, 6}, {15, 10}, {23, 7}, {24, 5}},
        {{10, 8}, {18, 7}, {25, 4}, {26, 2}},
        {{4, 5}, {6, 9}, {15, 6}, {18, 6}, {27, 3}},
        {{4, 6}, {9, 9}, {12, 10}, {14, 5}, {17, 2}, {18, 4}, {19, 6}},
        {{3, 7}, {12, 6}, {14, 6}, {23, 3}, {28, 8}},
        {{5, 5}, {9, 8}, {21, 9}, {22, 10}, {28, 6}, {29, 3}},
        {{6, 7}, {7, 8}, {9, 3}, {13, 7}, {19, 7}, {24, 8}},
        {{7, 8}, {8, 5}, {14, 2}, {15, 6}, {21, 5}, {23, 2}, {25, 3}},
        {{8, 5}, {9, 4}, {16, 8}, {17, 7}, {25, 6}, {26, 7}, {29, 4}},
        {{9, 4}, {10, 4}, {15, 3}, {17, 3}, {20, 8}, {25, 5}},
        {{10, 5}, {11, 6}, {16, 3}, {20, 3}, {22, 6}, {25, 2}, {28, 7}},
        {{11, 7}, {14, 10}, {19, 8}, {21, 7}, {24, 9}, {26, 5}},
        {{12, 5}, {14, 9}, {16, 8}, {19, 5}, {22, 3}, {27, 4}, {28, 3}},
        {{13, 4}, {14, 3}, {17, 6}, {18, 5}, {20, 4}, {23, 5}, {27, 6}},
        {{16, 2}, {19, 4}, {21, 2}, {22, 7}, {24, 4}, {26, 3}, {27, 2}},
        {{17, 3}, {19, 9}, {22, 9}, {25, 7}, {26, 6}},
        {{17, 6}, {20, 5}, {21, 6}, {23, 8}, {24, 7}, {26, 3}},
        {{18, 3}, {20, 2}, {22, 2}, {24, 3}, {25, 6}, {29, 6}},
        {{19, 3}, {22, 8}, {23, 4}, {27, 9}, {28, 5}, {29, 7}},
        {{20, 4}, {21, 3}, {26, 4}, {27, 5}, {28, 3}}};

    int V = 4;
    Prim(graph, V);
    return 0;
}
