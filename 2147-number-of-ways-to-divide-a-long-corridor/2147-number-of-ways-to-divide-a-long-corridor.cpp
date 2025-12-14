class Solution {
public:
    int M = 1e9 + 7; 
    int numberOfWays(string corridor) {
       int s(0), cnt(0);
       long long ways(1);

       for(auto &it:corridor){
            if(it=='S') s++;
            if(s>2) s%=2;
            if(s==2) cnt++;
            else{
                if(cnt) ways = (ways*cnt) % M;
                cnt=0;
            }
       }

       if(s!=2) return 0;
       return ways;
    }
};