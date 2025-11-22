#include <iostream>
#include <vector>

using namespace std;

int countPrimes(int n)
{

  vector<long long> prime(n);
  long long count = 0;

  for (int i = 2; i < n; i++)
  {
    prime[i] = 1;
  }

  for (int i = 2; i * i < n; i++)
  {
    for (int j = i * i; j < n; j += i)
    {
      prime[j] = 0;
    }
  }

  for (int i = 2; i < n; i++)
  {
    if (prime[i] == 1)
    {
      count++;
    }
  }

  cout << count << endl;
  return count;
}

int main()
{
  int n;
  cin >> n;
  countPrimes(n);
}