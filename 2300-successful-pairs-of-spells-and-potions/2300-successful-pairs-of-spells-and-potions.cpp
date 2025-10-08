class Solution {
public:

    int valid_pos(int spell, vector<int>& potions, long long success){
        long long potions_needed=(success + spell-1 )/spell;
        int l=0,r=potions.size();
        while(l<r){
            int mid= l+(r-l)/2;
            if (potions[mid]>= potions_needed)
                r=mid;
            else
                l=mid+1;
        }
        return l;  
    }


    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> res;

        for(auto spell:spells){
            res.push_back(potions.size()-valid_pos(spell, potions,success));
        }
        return res;
    }
};


// Using C++ STL
// vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
//         // sort(spells.begin(), spells.end());
//         sort(potions.begin(), potions.end());
//         vector<int> res;

//         for(auto spell:spells){
//             long long potions_needed = (success + spell-1)/spell;
//             auto temp = lower_bound(potions.begin(), potions.end(), potions_needed);
//             res.push_back(potions.end()-temp);
//         }
//         return res;
//     }