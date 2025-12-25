class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), [](int a, int b){
            return a>b;
        });

        long long s=happiness.size();

        long long sum = 0, i=0,turn = 0;
        while(k>0){
            long long curr = happiness[i]-turn;
            // sum = sum + max(0, happiness[i]-turn);
            if(curr <= 0) break;

            sum+=curr;
            k--;
            i++;
            turn++;
            // for(long long j=i+1; j<s; j++){
            //     if(happiness[j]>0){
            //         happiness[j]-=1;
            //     }
            // }
        }
        return sum;
    }
};