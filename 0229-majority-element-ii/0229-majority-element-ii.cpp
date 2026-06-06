//  //// OPTIMAL //// //
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0, n = nums.size();
        int majEl1 = INT_MIN, majEl2 = INT_MIN;
        int minOccurrence = (int)(n/3) + 1;

        for(int i = 0; i < nums.size(); i++){
            if(cnt1 == 0 && majEl2 != nums[i]){
                cnt1++;
                majEl1 = nums[i];
            }else if(cnt2 == 0 && majEl1 != nums[i]){
                cnt2++;
                majEl2 = nums[i];
            }else if(majEl1 == nums[i]){
                cnt1++;
            }else if(majEl2 == nums[i]){
                cnt2++;
            }else{
                cnt1--;
                cnt2--;
            }
        }

        vector<int> majorityEl;
        cnt1 = 0; cnt2 = 0;

        for(int i = 0; i < n; i++){
            if(majEl1 == nums[i])cnt1++;
            if(majEl2 == nums[i])cnt2++;    

        }

        if(cnt1 >= minOccurrence) majorityEl.push_back(majEl1);
        if(cnt2 >= minOccurrence) majorityEl.push_back(majEl2);
        return majorityEl;
    }
};


// // //// HASHING //// //
// // TC: O(n) SC: O(n)
// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> ans;
//         unordered_map<int ,int> mpp;

//         // Element is appearing atleast (n/3 + 1) times
//         int mn=(n/3)+1;

//         for(int i=0;i<n;i++){
//            mpp[nums[i]]++;

//             // Add it to the ans array as the count reaches (n/3 + 1)
//            if(mpp[nums[i]]==mn)
//                 ans.push_back(nums[i]);

//             // We can have atmost 2 elements
//             if(ans.size() == 2)
//                 break;

//         }
//         return ans;
//     }
// };



