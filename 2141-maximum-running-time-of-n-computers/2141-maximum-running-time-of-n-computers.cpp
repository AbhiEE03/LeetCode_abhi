class Solution {
public:
    using ll= long long;
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(), batteries.end());
        ll sum=0, b=batteries.size();
        for(ll i=0; i<b; i++){
            sum += batteries[i];
        }
        long long l=0, r=sum/n, result=0;

        while(l<=r){
            ll mid = l + (r-l)/2;

            // calculate total battery that can contribute max 'mid'
            ll target_mins = 0;
            for (ll x : batteries) {
                target_mins += min(x, mid);
            }

            if(target_mins>=mid*n){
                l = mid+1;
                result=max(result,mid);
            }else{
                r = mid-1;
            }
        }

        return result;
    }
};