// // //// QUESTION //// //
// Given an array nums of size n and an integer k, find the length of the longest sub-array that sums to k. If no such sub-array exists, return 0.

// Example 1

// Input: nums = [10, 5, 2, 7, 1, 9],  k=15

// Output: 4

// Explanation:

// The longest sub-array with a sum equal to 15 is [5, 2, 7, 1], which has a length of 4. This sub-array starts at index 1 and ends at index 4, and the sum of its elements (5 + 2 + 7 + 1) equals 15. Therefore, the length of this sub-array is 4.

// Example 2

// Input: nums = [-3, 2, 1], k=6

// Output: 0

// Explanation:

// There is no sub-array in the array that sums to 6. Therefore, the output is 0.

// Now your turn!

// Input: nums = [-1, 1, 1], k=1

// Output: 1

// Constraints

//  1<=n<=105
//  -105<=nums[i]<=105
//  -109<= k<=109

#include <bits/stdc++.h>
using namespace std;
// TC = O(n) SC = O(n)
// Most optimised when there are Negative, zero and positive elements
class Solution
{
public:
  int longestSubarray(vector<int> &nums, int k)
  {
    int maxLen = 0, n = nums.size();
    unordered_map<long long, int> mpp;
    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
      sum += nums[i];

      if (sum == k)
        maxLen = max(maxLen, i + 1);

      long long remove = sum - k;
      // If remove is there then we have got the sum = k
      if (mpp.find(remove) != mpp.end())
      {
        int len = i - mpp[remove];
        maxLen = max(maxLen, len);
      }

      // Push the sum in the unordered_map if it's not there
      if (mpp.find(sum) == mpp.end())
        mpp[sum] = i;
    }
    return maxLen;
  }
};

// TC = O(n) SC = O(1)
// Most optimised when there are only zero and positive elements
// 2 pointer Approach //
// class Solution{
// public:
//     int longestSubarray(vector<int> &nums, int k){
//         int l = 0, r = 0, maxLen = 0;
//         int sum = nums[0];
//         while(r < nums.size()){
//             while(l <= r && sum > k){
//                 sum -= nums[l];
//                 l++;
//             }

//             if(sum == k){
//                 maxLen = max(maxLen, r-l+1);
//             }

//             r++;
//             if(r < nums.size())
//                 sum +=  nums[r];

//         }
//         return maxLen;
//     }
// };
