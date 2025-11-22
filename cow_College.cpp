#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  long long cows;
  cin >> cows;
  vector<long long> tuition(cows);

  long long charge = 0, idx = 0, money;

  for (auto &i : tuition)
  {
    cin >> i;
  }

  sort(tuition.begin(), tuition.end()); // ascending order
  for (long long i = 0; i < cows; i++)
  {
    money = tuition[i] * (cows - i);
    if (money > charge)
    {
      charge = money;
      idx = tuition[i];
    }
  }
  cout << charge << ' ' << idx << '\n';
}