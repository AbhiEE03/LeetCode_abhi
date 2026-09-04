class Solution {
    using ll = long long;
    int mod = 1e9 + 7;

private:
    // It will calculate the power
    ll solve(ll x, ll n) {
        // Base Case
        if (n == 0)
            return 1;

        // to prevent the overflow
        x %= mod;

        // Actual pow logic along with overflow prevention
        if (n % 2 == 0)
            return solve((x * x) % mod, n / 2) ;
        return x * solve((x * x) % mod, (n - 1) / 2) % mod;
    }

public:
    int countGoodNumbers(long long n) {

        // For every even indices u have 5 options(0, 2, 4 , 6, 8)
        // For every odd indices u have 4 options(2, 3, 5, 7)
        // digit strings can have digits from 0-9
        // Naive way would be to do pow(5, (n+1)/2) * pow(4, n/2)
        ll even_indices = (n + 1) / 2;
        ll odd_indices = n / 2;
        return (solve(5, even_indices) * solve(4, odd_indices)) % mod;
    }
};