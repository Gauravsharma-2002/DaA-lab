#include <bits/stdc++.h>
using namespace std;
#define N 4

struct Node
{

    Node *parent;

    int pathCost;

    int cost;

    int workerID;

    int jobID;

    bool assigned[N];
};

Node *newNode(int x, int y, bool assigned[],
              Node *parent)
{
    Node *node = new Node;

    for (int j = 0; j < N; j++)
        node->assigned[j] = assigned[j];
    node->assigned[y] = true;

    node->parent = parent;
    node->workerID = x;
    node->jobID = y;

    return node;
}

int calculateCost(int costMatrix[N][N], int x,
                  int y, bool assigned[])
{
    int cost = 0;

    // unavailableJobs
    bool available[N] = {true};

    // start from next worker
    for (int i = x + 1; i < N; i++)
    {
        int min = INT_MAX, minIndex = -1;

        for (int j = 0; j < N; j++)
        {
            // if job is unassigned
            if (!assigned[j] && available[j] &&
                costMatrix[i][j] < min)
            {
                // store job number
                minIndex = j;

                // store cost
                min = costMatrix[i][j];
            }
        }

        // add cost of next worker
        cost += min;

        // job becomes unavailable
        available[minIndex] = false;
    }

    return cost;
}

struct comp
{
    bool operator()(const Node *lhs,
                    const Node *rhs) const
    {
        return lhs->cost > rhs->cost;
    }
};

void printAssignments(Node *min)
{
    if (min->parent == NULL)
        return;

    printAssignments(min->parent);
    cout << "Assign Worker " << char(min->workerID + 'A')
         << " to Job " << min->jobID << endl;
}

int findMinCost(int costMatrix[N][N])
{

    priority_queue<Node *, std::vector<Node *>, comp> que;

    // dummy node initialising with cost 0
    bool assigned[N] = {false};
    Node *root = newNode(-1, -1, assigned, NULL);
    root->pathCost = root->cost = 0;
    root->workerID = -1;

    que.push(root);

    // finding LIve nodes with least cost and deletion
    while (!que.empty())
    {
        // Find a live node with least estimated cost
        Node *min = que.top();

        // The found node is deleted from the list of
        // live nodes
        que.pop();

        int i = min->workerID + 1;

        // if all workers are assigned a job
        if (i == N)
        {
            printAssignments(min);
            return min->cost;
        }

        for (int j = 0; j < N; j++)
        {
            // If unassigned
            if (!min->assigned[j])
            {
                // create a new tree node
                Node *child = newNode(i, j, min->assigned, min);

                // cost for ancestors nodes including current node
                child->pathCost = min->pathCost + costMatrix[i][j];

                // calculate its lower bound
                child->cost = child->pathCost +
                              calculateCost(costMatrix, i, j, child->assigned);

                // Add child to list of live nodes;
                que.push(child);
            }
        }
    }
}

int main()
{
    // x-coordinate represents a Worker
    // y-coordinate represents a Job
    int costMatrix[N][N] =
        {
            {90, 75, 75, 80},
            {30, 85, 55, 65},
            {125, 95, 90, 105},
            {45, 110, 95, 115}};

    cout << "\nOptimal Cost is "
         << findMinCost(costMatrix);

    return 0;
}