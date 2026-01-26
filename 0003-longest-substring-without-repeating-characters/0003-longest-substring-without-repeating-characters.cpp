class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r=0, lsubstr=0;
        unordered_map <int,int> mpp;

        while(r<s.length()){
            while(mpp[s[r]]>0){
                mpp[s[l]]--;
                l++;
            }

            mpp[s[r]]++;
            lsubstr = max(lsubstr, r-l+1);
            r++;

            // if(mpp[s[r]]>=1){
            //     // int len = mpp.size();
            //     lsubstr = max(lsubstr, r-l);
            //     l++;
            //     mpp[s[r]]--;
            //     // r++;
            // }else {
            //     mpp[s[r]]++;
            //     r++;
            // }
        }
        return lsubstr;
    }
};