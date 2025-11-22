class Solution
{
public:
  int celebrity(vector<vector<int>> &M)
  {
    int top = 0, bottom = M.size() - 1;

    while (top < bottom)
    {
      if (M[top][bottom] == 1)
      {
        // top knows bottom → top can't be celeb
        top++;
      }
      else
      {
        // top doesn't know bottom → bottom can't be celeb
        bottom--;
      }
    }

    int candidate = top;
    for (int i = 0; i < M.size(); i++)
    {
      if (i == candidate)
        continue;
      if (M[candidate][i] == 1 || M[i][candidate] == 0)
      {
        return -1;
      }
    }

    return candidate;
  }
};
