class Solution {  
  public:  

    struct Job {
      int id;
      int deadline;
      int profit;
    };

    static bool comp(Job p1, Job p2) {
      return p1.profit > p2.profit;
    }

    vector<int> JobScheduling(vector<vector<int>>& Jobs) { 
        int n = Jobs.size();
        vector<Job> jobList(n);

        for (int i = 0; i < n; i++) {
            jobList[i] = {Jobs[i][0], Jobs[i][1], Jobs[i][2]};
        }

        sort(jobList.begin(), jobList.end(), comp);

        int totProfit = 0, count = 0, maxDeadline = -1;
        for (int i = 0; i < n; i++) maxDeadline = max(maxDeadline, jobList[i].deadline);

        vector<int> hash(maxDeadline + 1, -1);
        for (int i = 0; i < n; i++) {
          for (int j = jobList[i].deadline; j > 0; j--) {
            if (hash[j] == -1) {
              count++;
              totProfit += jobList[i].profit;
              hash[j] = jobList[i].id;
              break;
            }
          }
        }

        return {count, totProfit};
    } 
};
