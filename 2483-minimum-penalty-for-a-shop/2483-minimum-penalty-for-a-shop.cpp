class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();

        int minHour = 0;
        int penalty = count(customers.begin(), customers.end(), 'Y');
        int minPenalty = penalty;

        for(int i=0; i<n; i++){
            if(customers[i] == 'Y')
                penalty--;
            else
                penalty++;

            if(penalty < minPenalty){
                minPenalty = penalty;
                minHour = i+1;
            }
        }
        return minHour;
    }
};

// //// calculating prefix sum manually //// //
// class Solution {
// public:
//     // SC : O(n) & TC: O(n)
//     int bestClosingTime(string customers) {
//         int n = customers.size();
//         vector<int> prefix_N(n+1, 0);
//         vector<int> suffix_Y(n+1, 0);

//         // Filling prefix_N when we close the shop at ith hour
//         // Every N before i will contribute towards the penalty
//         for(int i = 1; i<=n; i++){
//             if(customers[i-1] == 'N')
//                 prefix_N[i] = prefix_N[i-1] + 1;
//             else
//                 prefix_N[i] = prefix_N[i-1];
//         }

//         // Filling suffix_N when we close the shop at ith hour
//         // Every Y after i will conntribute towards penalty
        
//         for(int i = n-1; i>=0; i--){
//             if(customers[i] == 'Y')
//                 suffix_Y[i] = suffix_Y[i+1] + 1;
//             else
//                 suffix_Y[i] = suffix_Y[i+1];
//         }

//         // Checking for minumum penalty
//         int penalty = INT_MAX;
//         int hour = INT_MAX;
//         for(int i=0; i<=n; i++){
//             int currPenalty = prefix_N[i] + suffix_Y[i];
//             if(currPenalty < penalty){
//                 penalty = currPenalty;
//                 hour = i;
//             }
//         }
//         return hour;
//     }
// };