class Solution {
    using ll = long long;
    int mod = 1e9 + 7;

private:
    // It will calculate the power
    ll solve(ll x, long long n) {
        // Base Case
        if (n == 0)
            return 1;

        x %= mod;
    
        if (n % 2 == 0)
            return solve((x * x) % mod, n / 2) ;
        return x * solve((x * x) % mod, (n - 1) / 2) % mod;
    }

public:
    int countGoodNumbers(long long n) {

        ll even_indices = (n + 1) / 2;
        ll odd_indices = n / 2;
        return (solve(5, even_indices) * solve(4, odd_indices)) % mod;
    }
};