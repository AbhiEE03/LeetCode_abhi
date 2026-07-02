class Solution {
public:
    bool isAnagram(string s, string t) {
        sort (s.begin(), s.end());
        sort (t.begin(), t.end());

        int s1 = s.size(), s2= t.size();
        if(s1 != s2)
            return false;

        for(int i =0; i<s.size(); i++){
            if(s[i] != t[i])
                return false;
        }
        return true;
    }
};