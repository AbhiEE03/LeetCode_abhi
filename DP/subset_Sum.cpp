#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isSubsetSum(vector<int> &arr, int sum)
  {
    int dp[arr.size() + 1][sum + 1];

    // Initialisataion
    // we can only get 0 sum with zero elements
    // we can always get zero sum irrespective of the number of elements

    for (int i = 0; i < arr.size() + 1; i++)
    {
      for (int j = 0; j < sum + 1; j++)
      {

        if (i == 0)
          dp[i][j] = false;
        if (j == 0)
          dp[i][j] = true;
      }
    }

    // Loop through the rest of the table and fill it
    for (int i = 1; i < arr.size() + 1; i++)
    {
      for (int j = 1; j < sum + 1; j++)
      {

        // Take an element or move on to the next
        if (arr[i - 1] <= j)
          dp[i][j] = (dp[i - 1][j - arr[i - 1]] || dp[i - 1][j]);
        else
          dp[i][j] = dp[i - 1][j];
      }
    }

    // Last grid will have the answer
    return dp[arr.size()][sum];
  }
};