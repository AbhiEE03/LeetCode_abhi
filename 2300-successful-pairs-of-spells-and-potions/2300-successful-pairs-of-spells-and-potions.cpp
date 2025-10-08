class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // sort(spells.begin(), spells.end());
        sort(potions.begin(), potions.end());
        vector<int> res;

        for(auto spell:spells){
            long long potions_needed = (success + spell-1)/spell;
            auto temp = lower_bound(potions.begin(), potions.end(), potions_needed);
            res.push_back(potions.end()-temp);
        }
        return res;
    }
};