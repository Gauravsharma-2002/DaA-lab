#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge
{
    int src, dest, weight;
};
struct Subset
{
    int parent, rank;
};
// Function to find the parent of a vertex (with path compression)
int find(vector<Subset> &subsets, int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}
// Function to perform union of two subsets (by rank)
void Union(vector<Subset> &subsets, int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
// Function to find the minimum cost spanning tree using Kruskal's algorithm
void Kruskal(vector<Edge> &edges, int V)
{
    // Sort edges by weight
    sort(edges.begin(), edges.end(), [](Edge &a, Edge &b)
         { return a.weight < b.weight; });
    // Allocate memory for subsets
    vector<Subset> subsets(V);
    for (int i = 0; i < V; ++i)
    {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
    int edgeCount = 0;
    int i = 0;
    // MST will have V-1 edges
    vector<Edge> MST(V - 1);
    // Iterate through all sorted edges
    while (edgeCount < V - 1 && i < edges.size())
    {
        Edge nextEdge = edges[i++];
        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);
        // Add edge to MST if it doesn't form a cycle
        if (x != y)
        {
            MST[edgeCount++] = nextEdge;
            Union(subsets, x, y);        }   }
    // Print MST
    cout << "Minimum Spanning Tree (MST):\n";
    for (int i = 0; i < V - 1; ++i)
    {        cout << MST[i].src << " - " << MST[i].dest << " (Weight: " << MST[i].weight << ")\n";    }}
int main()
{   // Example graph represented as a vector of edges
    vector<Edge> edges = {
        {0, 1, 4}, {0, 7, 8}, {1, 2, 8}, {1, 7, 11}, {2, 3, 7}, {2, 5, 4}, {2, 8, 2}, {3, 4, 9}, {3, 5, 14}, {4, 5, 10}, {5, 6, 2}, {6, 7, 1}, {6, 8, 6}, {7, 8, 7}, {7, 9, 1}, {8, 9, 2}, {9, 10, 4}, {10, 11, 7}, {11, 12, 9}, {12, 13, 10}, {13, 14, 2}, {14, 15, 1}, {15, 16, 6}, {16, 17, 7}, {17, 18, 4}, {18, 19, 2}, {19, 20, 3}, {20, 21, 3}, {21, 22, 4}, {22, 23, 3}, {23, 24, 2}, {24, 25, 2}, {25, 26, 1}, {26, 27, 1}, {27, 28, 3}, {28, 29, 4}, {29, 30, 2}, {30, 31, 1}, {31, 32, 3}, {32, 33, 4}, {33, 34, 5}, {34, 35, 6}, {35, 36, 7}, {36, 37, 5}, {37, 38, 4}, {38, 39, 3}, {39, 40, 2}, {40, 41, 1}, {41, 42, 2}, {42, 43, 3}, {43, 44, 4}, {44, 45, 5}, {45, 46, 4}, {46, 47, 3}, {47, 48, 2}, {48, 49, 1}, {49, 50, 2}, {50, 51, 3}, {51, 52, 2}, {52, 53, 3}, {53, 54, 4}, {54, 55, 5}, {55, 56, 6}, {56, 57, 5}, {57, 58, 4}, {58, 59, 3}, {59, 60, 2}, {60, 61, 1}, {61, 62, 2}, {62, 63, 3}, {63, 64, 4}, {64, 65, 3}, {65, 66, 2}, {66, 67, 1}, {67, 68, 2}, {68, 69, 3}, {69, 70, 2}, {70, 71, 1}, {71, 72, 2}, {72, 73, 3}, {73, 74, 4}, {74, 75, 3}, {75, 76, 2}, {76, 77, 1}, {77, 78, 2}, {78, 79, 3}, {79, 80, 4}, {80, 81, 3}, {81, 82, 2}, {82, 83, 1}, {83, 84, 2}, {84, 85, 3}, {85, 86, 2}, {86, 87, 1}, {87, 88, 2}, {88, 89, 3}, {89, 90, 4}, {90, 91, 3}, {91, 92, 2}, {92, 93, 1}, {93, 94, 2}, {94, 95, 3}, {95, 96, 2}, {96, 97, 1}, {97, 98, 2}, {98, 99, 3}};
    int V = 100;
    Kruskal(edges, V);
    return 0;}
