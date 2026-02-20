class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length(), m = str2.length();
        
        // INitialisation
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        // Code for LCS
        for(int i=1; i<n+1; i++){
            for( int j=1; j< m+1; j++){
                if(str1[i-1] == str2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        // Now that we have the LCS we can print the shortest supersequence using the grid
        // Start moving from the last cell anmd move in the direction of either the greater 
        // cell or the diagonal in case the elements are equal

        int i = n, j = m;
        string res="";
        while(i>0 && j>0){
            if(str1[i-1] == str2[j-1]){
                res.push_back(str1[i-1]);
                i--;
                j--;
            }
            else{
                if(dp[i-1][j] > dp[i][j-1]){
                    res.push_back(str1[i-1]);
                    i--;
                }
                // if(dp[i][j-1] > dp[i-1][j])
                else {
                    res.push_back(str2[j-1]);
                    j--;
                }
            }
        }

        while(i>0){
            res.push_back(str1[i-1]);
            i--;
        }
        while(j>0){
            res.push_back(str2[j-1]);
            j--;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};