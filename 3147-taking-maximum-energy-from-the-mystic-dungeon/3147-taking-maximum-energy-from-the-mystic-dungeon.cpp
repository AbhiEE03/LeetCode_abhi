class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        vector<int> prefix(n,0);

        for(int i=n-1; i>=0; i--){
            prefix[i]=energy[i];
            
           if(i+k < n){
            prefix[i]= prefix[i+k] + energy[i];
           }
        }

        return *max_element(prefix.begin(), prefix.end());
    }
};


// // BRUTE FORCE // 
// class Solution {
// public:
//     int maximumEnergy(vector<int>& energy, int k) {
//         int n=energy.size(), maxEnergy=INT_MIN;

//         for(int i=0; i<n; i++){
//             int temp=energy[i];
            
//             for(int j=i+k; j<n; j+=k){
//                 temp+=energy[j];
//             }

//             maxEnergy = max(maxEnergy, temp);

//         }
//         return maxEnergy;
//     }
// };