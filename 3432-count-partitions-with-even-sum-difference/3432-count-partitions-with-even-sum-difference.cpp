class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int partition = 0;
        int n= nums.size();
        int sumL=0,sum=0; 
        for(int i=0; i<n; i++){
            sum+=nums[i];
        }

        for(int it=0; it<n-1; it++){
            sumL+=nums[it];
            if(abs(sum - (2*sumL))%2 == 0) partition++;
        }
        return partition;
    }
};




// //// BRUTE FORCE APPROACH //// //
/*
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int partition = 0;
        int n= nums.size();
        int sumL=0, sumR=0;
        for(int i=0; i<n-1; i++){
            sumL += nums[i];
            for (int j = i+1; j<n; j++){
                sumR += nums[j];
            }
            if(abs(sumR - sumL)%2 == 0) partition++;
            sumR=0;
        }
        return partition;
    }
};
*/