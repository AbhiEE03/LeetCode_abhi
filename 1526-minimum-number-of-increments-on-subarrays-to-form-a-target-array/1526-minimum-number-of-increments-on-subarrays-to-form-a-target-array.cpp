class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans(0), last(0);

        for (auto &it: target){
            ans+=max(0, it-last);
            last=it;
        }

        return ans;
    }
};