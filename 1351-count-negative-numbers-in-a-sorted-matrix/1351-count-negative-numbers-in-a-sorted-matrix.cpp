class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count_neg=0;
        for(int i = 0; i<row; i++){

            int l=0, r = row-1;
            while(l<=r){
                int mid = l + (r-l)/2;
                if(grid[i][mid]<0)r = mid-1;
                else l = mid+1;
            }
            count_neg = count_neg + (col - l);
        }
        return count_neg;
    }
};