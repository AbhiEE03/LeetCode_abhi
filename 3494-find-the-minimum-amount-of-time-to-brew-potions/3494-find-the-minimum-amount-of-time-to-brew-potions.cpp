// class Solution {
// public:
//     long long minTime(vector<int>& skill, vector<int>& mana) {
//         int n=skill.size(),m=mana.size();

//         vector<long long> finishTime(n,0);

//         for(int j=0;j<m;j++){
//             finishTime[0] += mana[j] * skill[0];

//             for(int i=1;i<n;i++){
//                 finishTime[i]= max(finishTime[i], finishTime[i-1] + (1LL*mana[j]*skill[i]));
//             }

//             for(int i=n-1; i>0; i--){
//                 finishTime[i-1] = finishTime[i] - (1LL * mana[j] * skill[i]);
//             }
        
//         }

//         return finishTime[n-1];
//     }
// };

class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();
        long long sumSkill = 0;
        for (int x : skill) sumSkill += x;
        
        // prevWizardDone = time when the last wizard finishes the previous potion
        long long prevWizardDone = sumSkill * (long long)mana[0];
        
        for (int j = 1; j < m; j++) {
            long long prevPotionDone = prevWizardDone;
            // We will “simulate” backward the constraints among wizards
            for (int i = n - 2; i >= 0; i--) {
                // Remove the time the (i+1)-th wizard spent on potion j-1
                prevPotionDone -= (long long)skill[i + 1] * mana[j - 1];
                // For wizard i, their finish for potion j must respect both:
                //  - that this wizard’s last potion j-1 is done by prevPotionDone
                //  - that wizard i’s chain (prevWizardDone) minus their time on this potion j
                prevWizardDone = max(prevPotionDone,
                                     prevWizardDone - (long long)skill[i] * mana[j]);
            }
            // After adjusting, add the total time all wizards will spend on potion j
            prevWizardDone += sumSkill * (long long)mana[j];
        }
        
        return prevWizardDone;
    }
};
