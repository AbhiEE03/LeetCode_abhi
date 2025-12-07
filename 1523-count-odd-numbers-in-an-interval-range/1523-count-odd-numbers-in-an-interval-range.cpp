class Solution {
public:
    int countOdds(int low, int high) {
        long long odd=0, diff=high - low;
        odd= diff/2;
        if(low%2!=0 || high%2!=0) odd++;
        return odd;
    }
};