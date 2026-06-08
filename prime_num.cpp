#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;

// Defining a function that takes num from 0-n with all true by default
  vector<bool> prime(n + 1, true);

  //  0 and 1 can never be prime so we assigned it false
  prime[0] = prime[1] = false;

  // We will start checking from 2 so that we can mark the multiples of 2 as false along with 2
// Similarly from consecutive nums till n
  for (int i = 2; i * i <= n; i++)
  {
    if (prime[i])
    {
      for (int j = i * i; j <= n; j += i)
      {
        prime[j] = false;
      }
    }
  }


  // Since all the non primes have been marked false so all those haveing true value wwill be prime, so we will print it
  for (int i = 2; i <= n; i++)
  {
    if (prime[i])
      cout << i << " ";
  }
}