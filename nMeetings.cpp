#include <bits/stdc++.h>
using namespace std;

struct Meeting
{
  int start;
  int end;
  int index;
};

// Comparator to sort meetings by end time
bool compare(Meeting m1, Meeting m2)
{
  return m1.end < m2.end;
}

int maxMeetings(vector<int> &start, vector<int> &end)
{
  int n = start.size();
  vector<Meeting> meetings(n);

  for (int i = 0; i < n; i++)
  {
    meetings[i] = {start[i], end[i], i};
  }

  // Sort meetings based on their end time
  sort(meetings.begin(), meetings.end(), compare);

  int count = 1; // always select the first meeting
  int lastEndTime = meetings[0].end;

  for (int i = 1; i < n; i++)
  {
    if (meetings[i].start > lastEndTime)
    {
      count++;
      lastEndTime = meetings[i].end;
    }
  }

  return count;
}

int main()
{
  vector<int> start = {1, 3, 0, 5, 8, 5};
  vector<int> end = {2, 4, 6, 7, 9, 9};

  cout << "Maximum number of meetings: " << maxMeetings(start, end) << endl;
  return 0;
}
