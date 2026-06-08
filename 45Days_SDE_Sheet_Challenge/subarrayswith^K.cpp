// // //// QUESTION //// //

// Count subarrays with given xor K

// Given an array of integers nums and an integer k, return the total number of subarrays whose XOR equals to k.

// Example 1

// Input : nums = [4, 2, 2, 6, 4], k = 6

// Output : 4

// Explanation : The subarrays having XOR of their elements as 6 are [4, 2],  [4, 2, 2, 6, 4], [2, 2, 6], and [6]

// Example 2

// Input :nums = [5, 6, 7, 8, 9], k = 5

// Output : 2

// Explanation : The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]

// Now your turn!

// Input : nums = [5, 2, 9], k = 7

// Output:

// Constraints

//   1 <= nums.length <= 105
//   1 <= nums[i] <= 109
//   1 <= k <= 109

// THe approach is similar to the count subarrays with sum==k
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
  int subarraysWithXorK(vector<int> &nums, int k)
  {
    int xr = 0, count = 0;
    unordered_map<int, int> mpp;
    mpp[xr] = 1;

    for (int i = 0; i < nums.size(); i++)
    {
      xr ^= nums[i];
      int req = xr ^ k;
      count += mpp[req];
      mpp[xr]++;
    }
    return count;
  }
};