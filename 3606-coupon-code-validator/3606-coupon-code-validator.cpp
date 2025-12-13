class Solution {
public:
    // Function to check if the coupon is Valid 
    bool isValid(string &code){
            if(code.empty()) return false;
            for(char &ch : code){
                if(!isalnum(ch) && ch!='_') return false;
            }
            return true;
        }   


    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {

        // To sort them easily
        unordered_map<string,int> mpp = {{"electronics",0},{"grocery",1},{"pharmacy",2},{"restaurant",3}};

        vector<pair<int, string>> temp; //(Business Line INteger Value, Code)

        for(int i=0; i<code.size(); i++){
            if(isValid(code[i]) && mpp.count(businessLine[i]) && isActive[i])
                temp.push_back({mpp[businessLine[i]], code[i]});
        }

        sort(temp.begin(), temp.end());
        vector<string> result;

        for(auto it: temp){
            result.push_back(it.second);
        }
        return result;
    }

};