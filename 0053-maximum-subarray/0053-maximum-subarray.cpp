class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = INT_MIN, currSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i];

            sum = max(sum, currSum);

            if (currSum < 0)
                currSum = 0;
        }
        return sum;
    }
};

// // WE can get that subarray as well 
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int sum = INT_MIN, currSum = 0;
//         int start = -1, rnd = -1;

//         for (int i = 0; i < nums.size(); i++) {

//             if(sum == 0) start = i;
//             currSum += nums[i];

//             if(currSum > sum){
//                 end = i;
//             }
//             sum = max(sum, currSum);

//             if (currSum < 0)
//                 currSum = 0;
//         }
//         return sum;
//     }
// };