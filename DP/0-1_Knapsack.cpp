#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int knapsack(int W, vector<int> &val, vector<int> &wt)
  {

    int n = val.size();
    int dp[n + 1][W + 1];

    // Initialise the 1st row and 1st col with 0
    // For all other items, we can either take them or ignore
    // Whichever gives the max value
    for (int i = 0; i < n + 1; i++)
    {
      for (int j = 0; j <= W; j++)
      {

        if (i == 0 || j == 0)
          dp[i][j] = 0;

        else if (wt[i - 1] <= j)
          dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
        else
          dp[i][j] = dp[i - 1][j];
      }
    }

    // for(int i=1; i<n+1; i++){
    //     for(int j=1; j<=W; j++){
    //     }
    // }

    // Last grid contains the answer
    return dp[n][W];
  }
};