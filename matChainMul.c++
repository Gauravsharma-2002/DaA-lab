#include <bits/stdc++.h>
using namespace std;

int **dp;

int MatrixChainMultiplication(int mat[], int low, int high)
{

    if (low == high)
        return 0;

    if (dp[low][high] != -1)
        return dp[low][high];

    dp[low][high] = INT_MAX;

    for (int k = low; k < high; k++)
    {

        int cost = MatrixChainMultiplication(mat, low, k) +
                   MatrixChainMultiplication(mat, k + 1, high) +
                   mat[low - 1] * mat[k] * mat[high];

        if (cost < dp[low][high])
            dp[low][high] = cost;
    }
    // Returning the value dp[low][high],
    // since initially low=1, and high=n-1
    // therefore at last dp[1][n-1] will be returned.
    return dp[low][high];
}

int main()
{
    // This matrix chain of length 5 represents
    // example matrix with given dimension
    // 3*5, 5*6, 6*8, and 8*3.
    int mat[] = {3, 5, 6, 8, 3};
    int n = sizeof(mat) / sizeof(mat[0]);

    // memory assignment and initialisation with -1
    dp = new int *[n];
    for (int i = 0; i < n; i++)
    {
        dp[i] = new int[n];
        for (int j = 0; j < n; j++)
            dp[i][j] = -1;
    }
    cout << "Minimum number of steps are - ";
    cout << MatrixChainMultiplication(mat, 1, n - 1);
    return 0;
}