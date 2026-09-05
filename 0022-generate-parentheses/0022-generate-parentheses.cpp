// //// Approach -1 //// //

// class Solution {
// public:

//     bool isValid(string &curr){
//         int cnt = 0;
//         for(int i = 0; i < curr.length(); i++){
//             if(curr[i] == '(')
//                 cnt++;
//             else
//                 cnt--;
//             if(cnt < 0)
//                 return false;
//         }
//         return cnt == 0;
//     }

//     void solve(string &curr, int n, vector<string> &res){
//         // Base Case
//         if(curr.length() == 2*n){
//             if(isValid(curr))
//                 res.push_back(curr);
//             return;
//         }

//         curr.push_back('(');
//         solve(curr, n, res);
//         curr.pop_back();

//         curr.push_back(')');
//         solve(curr, n, res);
//         curr.pop_back();
//     }

//     vector<string> generateParenthesis(int n) {
//         string curr = "";
//         vector<string> res;
//         solve(curr, n, res);
//         return res;
//     }
// };

//  Approach - 2 //
class Solution {
public:
    void solve(string& curr, int n, vector<string>& res, int open, int close) {
        // Base Case
        if (curr.length() == 2 * n) {
                res.push_back(curr);
            return;
        }

        if (open < n) {
            curr.push_back('(');
            solve(curr, n, res, open+1, close);
            curr.pop_back();
        }

        if (close < open) {

            curr.push_back(')');
            solve(curr, n, res, open, close+1);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string curr = "";
        // int open(0), close(0);
        vector<string> res;
        solve(curr, n, res, 0, 0);
        return res;
    }
};