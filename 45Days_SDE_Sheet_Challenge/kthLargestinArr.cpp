// // //// QUESTION //// //
// K-th Largest element in an array

// Given an array nums, return the kth largest element in the array.
// Example 1

// Input: nums = [1, 2, 3, 4, 5], k = 2

// Output: 4

// Example 2

// Input: nums = [-5, 4, 1, 2, -3], k = 5

// Output: -5

// Now your turn!

// Input: nums = [11, 9, 8, 7, 3, 1], k = 4

// Output:

// Constraints

// 1 <= nums.length <= 105
// -1000 <= nums[i] <= 1000
// 1 <= k <= nums.length

#include <bits/stdc++.h>
using namespace std;

// n*O(log n) sorting
class Solution
{
public:
  int kthLargestElement(vector<int> &nums, int k)
  {

    // sort(nums.begin(), nums.end(), [](int a, int b){return a>b});
    sort(nums.begin(), nums.end(), greater<int>());
    return nums[k - 1];
  }
};
// n*O(log k) Heap
class Solution
{
public:
  int kthLargestElement(vector<int> &nums, int k)
  {

    priority_queue<
        int,
        vector<int>,
        greater<int>>
        pq;

    for (int num : nums)
    {
      pq.push(num);

      if (pq.size() > k)
      {
        pq.pop();
      }
    }

    return pq.top();
  }
};