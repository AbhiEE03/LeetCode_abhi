class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size(), maxEnergy=INT_MIN;

        for(int i=0; i<n; i++){
            int temp=energy[i];
            for(int j=i+k; j<n; j+=k){
                temp+=energy[j];
            }

            maxEnergy = max(maxEnergy, temp);

        }
        return maxEnergy;
    }
};