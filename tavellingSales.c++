
#include <bits/stdc++.h>
using namespace std;
#define V 4

int travllingSalesmanProblem(int graph[][V], int s)
{
    // storing vertx exept source vrtx
    vector<int> vertex;
    for (int i = 0; i < V; i++)
        if (i != s)
            vertex.push_back(i);

    // storing min wht Hamiltonian Cycle.
    int min_path = INT_MAX;
    int i = 0;
    do
    {

        // store current Path weight(cost)
        int current_pathweight = 0;

        // compute current path weight
        int k = s;
        for (int i = 0; i < vertex.size(); i++)
        {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];
        cout << "currentPath " << i++ << " : " << current_pathweight << "\n";

        // update minimum
        min_path = min(min_path, current_pathweight);
        // cout <<"current Path : "<< current_pathweight << " \n";

    } while (
        next_permutation(vertex.begin(), vertex.end()));

    return min_path;
}

// Driver Code
int main()
{
    // matrix representation of graph
    int graph[][V] = {
        {0, 20, 42, 35},
        {20, 0, 30, 34},
        {42, 30, 0, 12},
        {35, 34, 12, 0}};
    int s = 0;
    cout << "minimum path: " << travllingSalesmanProblem(graph, s) << endl;
    return 0;
}