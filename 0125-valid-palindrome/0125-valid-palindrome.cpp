class Solution {
public:
    bool alpha_numeric(char ch){
        if((ch>='0' && ch<='9') | (tolower(ch)>='a' && tolower(ch)<='z'))return true;
        return false;
    }

    bool isPalindrome(string s) {
        int n = s.length();
        int l=0, r=n-1;
        while(l<=r){
            if(!alpha_numeric(s[l])){
                l++; 
                continue;
            }
            if(!alpha_numeric(s[r])){
                r--; 
                continue;
            }

            if(tolower(s[l]) != tolower(s[r])) return false;
            l++;
            r--;
        }
        return true;
    }
};