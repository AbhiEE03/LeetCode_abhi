class Solution {
public:
    int climbStairs(int n) {
    // Space optimized solution
    // We need only the prev and prev2 data
        int prev = 1, prev2 = 1;
        for(int i=2; i<=n; i++){
            int curr_stair = prev + prev2;
            prev2 = prev;
            prev = curr_stair;
        }
        return prev;
    }
};


// //// 1D dp solution //// //
// class Solution {
// public:
//     int climbStairs(int n) {
//         // Initialisation
//         // There is only 1 way to be at 0th and 1st index (Base Case)
//         vector<int> dp(n+1, 1);
        
//         // Base Case which are already initialised
//         // dp[0] = 1;
//         // dp[1] = 1;

//         //  Total Ways = sum of ways to reach the prev and prev2 stairs
//         for(int i=2; i<=n; i++){
//             dp[i] = dp[i-1] + dp[i-2];
//         }
//         return dp[n];
//     }
// };