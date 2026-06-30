// TC: O(n*m), SC: O(1)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";

        for (int i = 0; i < strs[0].size(); i++) {
            char ch = strs[0][i];

            for (int j = 1; j < strs.size(); j++) {

                // current string is smaller
                if (i >= strs[j].size())
                    return ans;

                // characters don't match
                if (ch != strs[j][i])
                    return ans;
            }
            // since you didn't return that means all char at this index are
            // equal
            ans += ch;
        }
        return ans;
    }
};