#include <bits/stdc++.h>
using namespace std;

// find len(longest increasing subsequence)
int getAns(int arr[], int n, int ind, int prev_index, vector<vector<int>> &tabu)
{
    // Base condition
    if (ind == n)
        return 0;

    if (tabu[ind][prev_index + 1] != -1)
        return tabu[ind][prev_index + 1];

    int notTake = 0 + getAns(arr, n, ind + 1, prev_index, tabu);

    int take = 0;

    if (prev_index == -1 || arr[ind] > arr[prev_index])
    {
        take = 1 + getAns(arr, n, ind + 1, ind, tabu);
    }

    return tabu[ind][prev_index + 1] = max(notTake, take);
}

int longestIncreasingSubsequence(int arr[], int n)
{
    // Create a 2D tabu array initialized to -1
    vector<vector<int>> tabu(n, vector<int>(n + 1, -1));

    return getAns(arr, n, 0, -1, tabu);
}

int main()
{
    int arr[] = {110, 19, 12, 15, 23, 37, 101, 108, 25, 54, 145, 74, 58, 64, 25, 21, 47, 85, 69, 75};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "The length of the longest increasing subsequence is " << longestIncreasingSubsequence(arr, n);

    return 0;
}