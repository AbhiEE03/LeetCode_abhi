class Solution {
public:
    bool isPalindrome(int x) {      
        string s = to_string(x);
        int n = s.size(), r=n-1, l=0;

        while(l<=r){
            if(s[l]!=s[r]) return false;
            l++;r--;
        }
        return true;
    }
};