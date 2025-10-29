class Solution {
public:
    int totalMoney(int n) {
        long long money=0;  

        int weeks = n/7;
        int rem_Days = n%7;

        int rem_Money= (rem_Days * (rem_Days+1))/2 + weeks*rem_Days;

        money= (28 * weeks) + (7*weeks*(weeks-1))/2 + rem_Money;

        return money;
        
    }
};