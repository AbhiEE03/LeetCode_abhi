class Solution {
public:

    bool isValid(string &curr){
        int cnt = 0;
        for(int i = 0; i < curr.length(); i++){
            if(curr[i] == '(')
                cnt++;
            else
                cnt--;
            if(cnt < 0)
                return false;
        }
        return cnt == 0;
    }

    void solve(string &curr, int n, vector<string> &res){
        // Base Case
        if(curr.length() == 2*n){
            if(isValid(curr))
                res.push_back(curr);
            return;
        }

        curr.push_back('(');
        solve(curr, n, res);
        curr.pop_back();

        curr.push_back(')');
        solve(curr, n, res);
        curr.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        string curr = "";
        vector<string> res;
        solve(curr, n, res);
        return res;
    }
};