class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {

        int ans=INT_MAX, n=timePoints.size();
        vector<int> minutes; //O(n)

        for(int i=0;i<n;i++){

        string str=timePoints[i];

        // Take hour and minutes substrings and convert them to integers
        int hourSubstring= stoi(str.substr(0,2));
        int minSubstring= stoi(str.substr(3,2)); //.substr(startIndex, Size)

        int totalMin=(hourSubstring*60) + minSubstring;

        // Minutes array to store all the time after converting them to minutes
        minutes.push_back(totalMin);
        }

        // O(nlogn)
        sort(minutes.begin(),minutes.end());

        for(int i=1;i<minutes.size();i++){
            // Take differene between adjacent values
            ans=min(ans,minutes[i] - minutes[i-1]);
        }

        //For end Points that can be closer to each other compared to their adjacent values
        // Get the difference bet that point and 00:00 then add the smallest time (minutes[0])
        ans=min(ans, (1440-minutes.back()) + minutes.front()); 
        
        return ans;
    }
};