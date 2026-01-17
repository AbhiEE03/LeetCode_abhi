class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n= s.length(), p = part.length();

        while(n>0 && s.find(part) < n){
            int r = s.find(part);
            s.erase(r, p);
        }
        return s;
    }
};