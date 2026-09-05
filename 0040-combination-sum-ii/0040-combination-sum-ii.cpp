class Solution {
private:
    void findComb(int idx, int target, vector<int>& arr, vector<int> &curr,
    vector<vector<int>> &final){
        // Base Case
        if(target == 0){
            final.push_back(curr);
            return;
        }

        // For every idx, u have to make calls till n-1
        for(int i = idx; i < arr.size(); i++){

            // If the consecutive elements are equal then skip them after picking the first one 
            if(i > idx && arr[i] == arr[i-1])
                continue;

            if(arr[i] > target)
                break;

            curr.push_back(arr[i]);
            findComb(i+1, target-arr[i], arr, curr, final);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // Since u need the unique combinations that too in 
        // lexicographical order
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> final;
        vector<int> curr;

        findComb(0, target, candidates, curr, final);
        return final;
        
    }
};