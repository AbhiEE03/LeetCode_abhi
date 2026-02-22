#include <bits/stdc++.h>
using namespace std;

// //// Space Optimized //// //
class Solution
{
public:
  int frogJump(vector<int> &heights)
  {

    int n = heights.size();
    if (n == 1)
      return 0;
    int prev2 = 0;
    int prev = abs(heights[1] - heights[0]);
    ;

    for (int i = 2; i < n; i++)
    {
      int curr = min(prev + abs(heights[i] - heights[i - 1]), prev2 + abs(heights[i] - heights[i - 2]));
      prev2 = prev;
      prev = curr;
    }
    return prev;
  }
};

// //// 1D DP Approach //// //
class Solution
{
public:
  int frogJump(vector<int> &heights)
  {
    // Initialisation
    int n = heights.size();
    vector<int> dp(n, -1);
    // Base Case = For going on 0th stair we need no cost
    if (n == 1)
      return 0;
    dp[0] = 0;
    dp[1] = abs(heights[1] - heights[0]);

    for (int i = 1; i < n; i++)
    {
      // we have to choose between the min among going from (i-1)th or (i-2)th stair
      dp[i] = min(dp[i - 1] + abs(heights[i] - heights[i - 1]), dp[i - 2] + abs(heights[i] - heights[i - 2]));
    }
    // We have to go till (n-1)th stair
    return dp[n - 1];
  }
};