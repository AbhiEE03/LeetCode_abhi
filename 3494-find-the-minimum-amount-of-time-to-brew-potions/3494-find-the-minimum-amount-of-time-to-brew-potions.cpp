class Solution {
public:
    using ll = long long;
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<ll> times(n);
        for (int j = 0; j < m; j++) {
            ll cur_time = 0;
            for (int i = 0; i < n; i++) {
                cur_time = max(cur_time, times[i]) + skill[i] * mana[j];
            }
            times[n - 1] = cur_time;
            for (int i = n - 2; i >= 0; i--) {
                times[i] = times[i + 1] - skill[i + 1] * mana[j];
            }
        }
        return times[n - 1];
    }
};



// Didn't get this approach so pasting the official leetcode solution above this
// class Solution {
// public:
//     long long minTime(vector<int>& skill, vector<int>& mana) {
//         int n=skill.size(),m=mana.size();

//         vector<long long> finishTime(n,0);

//         for(int j=0; j<m ; j++){
//             finishTime[0] += mana[j] * skill[0];

//             for(int i=1; i<n; i++){
//                 finishTime[i]= max(finishTime[i], finishTime[i-1]) + (1LL*mana[j]*skill[i]);
//             }

//             for(int i=n-1; i>0; i--){
//                 finishTime[i-1] = finishTime[i] - (1LL * mana[j] * skill[i]);
//             }
        
//         }

//         return finishTime[n-1];
//     }
// };
