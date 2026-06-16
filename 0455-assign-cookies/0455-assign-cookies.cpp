// class Solution {
// public:
//     int findContentChildren(vector<int>& g, vector<int>& s) {
//         sort(s.begin(),s.end());
//         sort(g.begin(),g.end());
//         int l=0,r=0;
//         int count=0;

//         while(l<g.size() && r<s.size()){
//             if(s[r]>=g[l]){
//                 l++;r++;count++;
//             }else r++;
//         }
//         return count;
        
//     }
// };


// I wrote the exact same code during the revision through SDESheetChallenge
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int l = 0, r = 0, contentChild = 0;
        while(l < g.size() && r < s.size()){
            if(g[l] <= s[r]){
                contentChild++;
                l++;
                r++;
            }else{
                r++;
            }
        }
        return contentChild;
    }
};