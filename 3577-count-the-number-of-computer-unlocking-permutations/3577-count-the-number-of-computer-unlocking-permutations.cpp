class Solution {
public:
    int M=1e9+7;
    int countPermutations(vector<int>& complexity) {
        long long result=1;

        for(int i=1; i<complexity.size(); i++){
            if(complexity[i]<=complexity[0]) return 0;

            result =(1LL * result * i)%M; 
        }
        return result;
    }
};