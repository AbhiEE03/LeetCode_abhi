class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n= digits.size();
        for (int i=n-1; i>=0; i--){
            if(digits[i]==9){
                if(i==0){
                    digits.push_back(0);
                    digits[0]=1;
                }else digits[i]=0;
            }else{
                digits[i]++;
                return digits;
            }
        }
        return digits;
    }
};