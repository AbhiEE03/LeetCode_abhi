#include <bits/stdc++.h>
using namespace std;

int main()
{
  int low, high;
  cin >> low >> high;

  long long odd = 0, diff = high - low;
  odd += diff / 2;
  if (low % 2 != 0 || high % 2 != 0)
    odd++;

  cout << odd << endl;
}
