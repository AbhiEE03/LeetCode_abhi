class Solution {
public:
    // It will calculate the power
    double solve(double x, long long n){
        // Base Case
        if(n==0) return 1;

        // Convert negative to positive then call using reciprocal
        if(n<0) return solve(1/x, -1*n);

        if(n%2==0) return solve(x*x, n/2);
        return x * solve(x*x, (n-1)/2);
    }

    double myPow(double x, int n) {
       return solve(x, (long long)n);
    }
};