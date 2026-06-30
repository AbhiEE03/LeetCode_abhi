class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string temp ="";
        int cnt = 0;

        // keep adding a until the size exceeds b
        while(temp.size() < b.size()){
            temp+=a;
            cnt++;
        }

        // check if b is a substring of temp
        if(temp.find(b) != string::npos)
            return cnt;

        // If not a substr then do 1 more repeatition
        temp+=a;
        cnt++;

        if(temp.find(b) != string::npos)
            return cnt;

        return -1;
    }
};