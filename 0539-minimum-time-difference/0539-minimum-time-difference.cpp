class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {

        int ans=INT_MAX,n=timePoints.size();
        vector<int> minutes;

        for(int i=0;i<n;i++){

        string str=timePoints[i];

        int hourSubstring= stoi(str.substr(0,2));
        int minSubstring= stoi(str.substr(3,2)); //.substr(startIndex, Size)

        int totalMin=(hourSubstring*60) + minSubstring;

        minutes.push_back(totalMin);
        }

        sort(minutes.begin(),minutes.end());

        for(int i=0;i+1<minutes.size();i++){
            int diff= minutes[i+1] - minutes[i];
            ans=min(ans,diff);
        }
        ans=min(ans, 1440-(minutes.back()-minutes.front()));
        return ans;
    }
};