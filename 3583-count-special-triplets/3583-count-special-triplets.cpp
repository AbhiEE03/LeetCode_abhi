class Solution {
public:
    int M=1e9+7;
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> mpp_right;
        unordered_map<int, int> mpp_left;

        for(auto it: nums) mpp_right[it]++;

        long long count=0;
        for(int j=0; j<nums.size(); j++){
            int x=nums[j];
            mpp_right[x]--;

            long long req = x*2;

            count= (count + (1LL * mpp_left[req] * mpp_right[req]))%M;

            mpp_left[x]++;
        }
        return count;
    }
};




// ///// BRUTE FORCE //// //
// class Solution {
// public:
//     int specialTriplets(vector<int>& nums) {
//         int n = nums.size();
//         long long count=0;
//         for(int i=0; i<n-2; i++){
//             for(int j=i+1; j<n-1; j++){
//                 for(int k=j+1; k<n; k++){
//                     if(nums[j]*2==nums[i] && nums[j]*2==nums[k]) count++;
//                 }
//             }
//         }
       
//         return count;
//     }
// };