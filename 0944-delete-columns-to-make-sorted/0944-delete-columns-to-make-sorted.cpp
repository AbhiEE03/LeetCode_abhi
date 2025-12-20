class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int c = strs[0].size();

        int deleted=0;
        for(int col = 0; col<c; col++){
            for(int row=1; row<n; row++){
                if(strs[row][col] < strs[row-1][col]){
                    deleted++;
                    break;
                }
            }
        }
        return deleted;
        
    }
};