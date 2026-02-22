#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isDigitorialPermutation(int n)
  {

    int original = n;
    vector<long long> factorial(10);
    factorial[0] = 1;
    for (int i = 1; i < 10; i++)
    {
      factorial[i] = factorial[i - 1] * i;
    }
    long long sum = 0;
    while (n > 0)
    {
      int digit = n % 10;
      sum += factorial[digit];
      n = n / 10;
    }

    string org = to_string(original);
    string s = to_string(sum);
    sort(org.begin(), org.end());
    sort(s.begin(), s.end());
    return s == org;
  }
};