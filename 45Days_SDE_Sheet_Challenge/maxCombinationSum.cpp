// // //// QUESTION //// //
// Maximum Sum Combination
// Given two integer arrays nums1 and nums2 and an integer k,
// return the maximum k valid sum combinations from all possible
// sum combinations using the elements of nums1 and nums2.

// A valid sum combination is made by adding one element from
// nums1 and one element from nums2. Return the answer in non-increasing order.

// Example 1

// Input: nums1 = [7, 3], nums2 = [1, 6], k = 2

// Output: [13, 9]

// Explanation:

// The 2 maximum combinations are made by:

// nums1[0] + nums2[1] = 13

// nums1[1] + nums2[1] = 9

// Example 2

// Input: nums1 = [3, 4, 5], nums2 = [2, 6, 3], k = 2

// Output: [11, 10]

// Explanation:

// The 2 maximum combinations are made by:

// nums1[2] + nums2[1] = 11

// nums1[1] + nums2[1] = 10

// Now your turn!

// Input: nums1 = [2, 2], nums2 = [5, 5], k = 2

// Output:

// Constraints

// n == size of nums1 & nums2
// 1 <= n <= 105
// 1 <= Each element of nums1 & nums2 <= 104
// 1 <= k <= n * n

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> maxSumCombinations(vector<int> &nums1,
                                 vector<int> &nums2,
                                 int k)
  {

    int n = nums1.size();

    // Sort both arrays in descending order
    sort(nums1.begin(), nums1.end(), greater<int>());
    sort(nums2.begin(), nums2.end(), greater<int>());

    // Max Heap:
    // {sum, {i, j}}
    priority_queue<pair<int, pair<int, int>>> pq;

    // To avoid processing the same pair twice
    set<pair<int, int>> vis;

    // Largest possible sum
    pq.push({nums1[0] + nums2[0], {0, 0}});
    vis.insert({0, 0});

    vector<int> ans;

    while (k--)
    {

      auto top = pq.top();
      pq.pop();

      int sum = top.first;
      int i = top.second.first;
      int j = top.second.second;

      ans.push_back(sum);

      // Move down => (i+1, j)
      if (i + 1 < n && vis.find({i + 1, j}) == vis.end())
      {

        pq.push({nums1[i + 1] + nums2[j],
                 {i + 1, j}});

        vis.insert({i + 1, j});
      }

      // Move right => (i, j+1)
      if (j + 1 < n && vis.find({i, j + 1}) == vis.end())
      {

        pq.push({nums1[i] + nums2[j + 1],
                 {i, j + 1}});

        vis.insert({i, j + 1});
      }
    }

    return ans;
  }
};