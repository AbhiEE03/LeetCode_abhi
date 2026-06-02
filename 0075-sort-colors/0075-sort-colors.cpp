// THe first soln can be using MERGE SORT but that will take extra space so I'll procees with the better soln first
// BETTER //
// I'll loop through the array and ttract the occurences of 0,1 and 2 then manually overwrite the array 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0 = 0, count1 = 0, count2 = 0;

        // Counting the occurrences of 0,1 and 2
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0)count0++;
            else if(nums[i] == 1)count1++;
            else count2++;
        }

        // Overwrite the values in order according to occurrences
        for(int i = 0; i < count0; i++)
            nums[i] = 0;
        for(int i = count0; i < count0+count1; i++)
            nums[i] = 1;
        for(int i = count0+count1; i < count0+count1+count2; i++)
            nums[i] = 2;
    }
};