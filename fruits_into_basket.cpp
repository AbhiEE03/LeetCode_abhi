#include <bits/stdc++.h>
using namespace std;

// Better Solution
// Keep putting the fruits in the map and store their frequency
// As you exceed the size=2, remove the fruits startong from left end until u again have
// only 2 types of fruits
// Erase the type of fruits with zero frequency
// Increment l while size>2 and r when size<=2
class Solution
{
public:
  int totalFruits(vector<int> &fruits)
  {
    int l = 0, r = 0, maxlen = 0;
    unordered_map<int, int> mpp;
    while (r < fruits.size())
    {
      mpp[fruits[r]]++;

      if (mpp.size() > 2)
      {
        while (mpp.size() > 2)
        {
          mpp[fruits[l]]--;
          if (mpp[fruits[l]] == 0)
            mpp.erase(fruits[l]);
          l++;
        }
      }

      maxlen = max(maxlen, r - l + 1);
      r++;
    }
    return maxlen;
  }
};

// OPTIMAL
// Instead of reducing l until we get a valid subarray in one step we do
// one decrement at a time.
// In this way we avoid incrementing l multiple times in one go and reduce the
//  work per iteration.

// Comaprison between both //
// The TC = O(2N) = O(N) in both the cases the only difference is in the way
// we are shrinking the window one by one in second case which can be useful
// when it's costly to shrink, the window isn't valid all the time in 2nd case
//  as it might have 3 types of fruits in some iterations
// We can prefer the 1st solution when shrinking isn't costly
// Prefer 2nd when shrinking is costly and we want uniform per iteratioin cost
class Solution
{
public:
  int totalFruits(vector<int> &fruits)
  {
    int l = 0, r = 0, maxlen = 0;
    unordered_map<int, int> mpp;
    while (r < fruits.size())
    {
      mpp[fruits[r]]++;

      if (mpp.size() > 2)
      {
        // Remove only one element at leftmost pointer in one move
        mpp[fruits[l]]--;
        if (mpp[fruits[l]] == 0)
          mpp.erase(fruits[l]);
        l++;
      }
      if (mpp.size() <= 2)
      {
        maxlen = max(maxlen, r - l + 1);
        r++;
      }
    }
    return maxlen;
  }
};