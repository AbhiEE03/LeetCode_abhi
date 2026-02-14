#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int longestCommonSubstr(string str1, string str2)
  {

    //   Initialisation
    int n = str1.length(), m = str2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    int res = 0;
    for (int i = 1; i < n + 1; i++)
    {
      for (int j = 1; j < m + 1; j++)
      {
        if (str1[i - 1] == str2[j - 1])
          dp[i][j] = 1 + dp[i - 1][j - 1];
        else
          dp[i][j] = 0;

        res = max(res, dp[i][j]);
      }
    }

    return res;
  }
};
