class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int c = strs[0].size();

        int deleted=0,marked;
        for(int i=1; i<n; i++){
            for(int j=0; j<c; j++){
                if(j != marked && (strs[i][j] < strs[i-1][j]) && deleted < n){
                    deleted++;
                    marked = j;

                }
            }
        }
        return deleted;
        
    }
};