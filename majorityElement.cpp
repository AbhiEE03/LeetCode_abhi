// Brute-Force Approach

// #include <iostream>
// #include <vector>

// using namespace std;

// int majorityElement(vector<int> &arr)
// {
//   int n = arr.size();

//   int count = 0;

//   for (int val : arr)
//   {
//     for (int el : arr)
//     {
//       if (el == val)
//       {
//         count++;
//       }
//     }
//     if (count > n / 2)
//     {
//       return val;
//     }
//   }
//   return -1;
// };

// int main()
// {
//   vector<int> arr = {3, 2, 2, 3, 3};

//   cout << majorityElement(arr);

//   return 0;
// }

////////// Optimal (By sorting)/////////////

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int majorityElement(vector<int> &arr)
// {
//   int n = arr.size();

//   // Sort
//   sort(arr.begin(), arr.end());

//   // Freq count
//   int count = 1, ans = arr[0];
//   for (int i = 1; i < n; i++)
//   {
//     if (arr[i] == arr[i - 1])
//     {
//       count++;
//     }
//     else
//     {
//       count = 1, ans = arr[i];
//     }
//     if (count > n / 2)
//     {
//       return ans;
//     }
//   }
//   return ans;
// }

// int main()
// {
//   vector<int> arr = {3, 2, 2, 3, 3};
//   cout << majorityElement(arr);
// }

////////// Moore's Voting Algorithm/////////////

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int majorityElement(vector<int> &arr)
{
  int freq = 0, ans = 0;

  for (int i = 0; i < arr.size(); i++)
  {
    if (freq == 0)
    {
      ans = arr[i];
    }
    if (ans == arr[i])
    {
      freq++;
    }
    else
    {
      freq--;
    }
  }
  return ans;
}

int main()
{
  vector<int> arr = {3, 2, 2, 3, 3};
  cout << majorityElement(arr);
}
