// // ////QUESTIONS //// //
// N meetings in one room
// Subscribe to TUF+

// Hints
// Company
// Given one meeting room and N meetings represented by two arrays, start and end, where start[i] represents the start time of the ith meeting and end[i] represents the end time of the ith meeting, determine the maximum number of meetings that can be accommodated in the meeting room if only one meeting can be held at a time.

// Example 1

// Input : Start = [1, 3, 0, 5, 8, 5] , End = [2, 4, 6, 7, 9, 9]

// Output : 4

// Explanation : The meetings that can be accommodated in meeting room are (1,2) , (3,4) , (5,7) , (8,9).

// Example 2

// Input : Start = [10, 12, 20] , End = [20, 25, 30]

// Output : 1

// Explanation : Given the start and end time, only one meeting can be held in meeting room.

// Now your turn!

// Input : Start = [1, 4, 6, 9] , End = [2, 5, 7, 12]

// Output:
// Constraints

// 1 <= N <= 105
// 0 <= start[i] < end[i] <= 105

// Approach-1 with struct //

#include <bits/stdc++.h>
using namespace std;

// struct Meeting
// {
//   int start;
//   int end;
//   int index;
// };

// // Comparator to sort meetings by end time
// bool compare(Meeting m1, Meeting m2)
// {
//   return m1.end < m2.end;
// }

// int maxMeetings(vector<int> &start, vector<int> &end)
// {
//   int n = start.size();
//   vector<Meeting> meetings(n);

//   for (int i = 0; i < n; i++)
//   {
//     meetings[i] = {start[i], end[i], i};
//   }

//   // Sort meetings based on their end time
//   sort(meetings.begin(), meetings.end(), compare);

//   int count = 1; // always select the first meeting
//   int lastEndTime = meetings[0].end;

//   for (int i = 1; i < n; i++)
//   {
//     if (meetings[i].start > lastEndTime)
//     {
//       count++;
//       lastEndTime = meetings[i].end;
//     }
//   }

//   return count;
// }

// int main()
// {
//   vector<int> start = {1, 3, 0, 5, 8, 5};
//   vector<int> end = {2, 4, 6, 7, 9, 9};

//   cout << "Maximum number of meetings: " << maxMeetings(start, end) << endl;
//   return 0;
// }

// Approach-2 w/o struct but 2D vector //
class Solution
{
public:
  int maxMeetings(vector<int> &start, vector<int> &end)
  {
    int n = start.size();

    // Use a 2D vector instead of a struct: {start, end, original_index}
    vector<vector<int>> meetings(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
      meetings[i] = {start[i], end[i], i};
    }

    sort(meetings.begin(), meetings.end(), [](const vector<int> &a, const vector<int> &b)
         {
           return a[1] < b[1]; // Sort by end time (index 1)
         });

    int count = 1;
    int lastEndTime = meetings[0][1]; // 1st meet

    for (int i = 1; i < n; i++)
    {
      if (meetings[i][0] > lastEndTime)
      {
        count++;
        lastEndTime = meetings[i][1];
      }
    }

    return count;
  }
};
