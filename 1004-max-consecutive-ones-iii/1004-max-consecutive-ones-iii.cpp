class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0, r=0, maxOnes=0;
        // Keep a count of zeros in the array
        int zeros = 0;
        while(r < nums.size()){

            // Increment if u encounter a zero
            if(nums[r] == 0)
                zeros++;
            
            // Keep incrementing l, until u r having zeros>k
            // And reduce the zeros count if there is a zero at leftmost position
            while(zeros > k){
                if(nums[l] == 0)
                    zeros--;
                l++;
            }
            // If we are out of while loop that means it's safe to count the maxOnes length
            // and move the right pointer
            maxOnes = max(maxOnes, r-l+1);
            r++;

        }
        return maxOnes;
    }
};