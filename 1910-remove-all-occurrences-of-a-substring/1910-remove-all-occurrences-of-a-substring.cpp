class Solution {
public:
    string removeOccurrences(string s, string part) {
        int p = part.length();

        while(s.find(part) != string::npos){
            int r = s.find(part);
            s.erase(s.find(part), p);
        }
        return s;
    }
};