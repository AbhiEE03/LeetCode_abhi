class Solution {
public:
    // The recursive cconverter function
    int converter(string& s, int i, long long num, int sign) {
        // Base Condition
        if (i >= s.size() || !isdigit(s[i]))
            return num * sign;

        // Forming the number
        num = num * 10 + (s[i] - '0');

        long long val = sign * num;
        if (val < INT_MIN)
            return INT_MIN;
        if (val > INT_MAX)
            return INT_MAX;

        return converter(s, i + 1, num, sign);
    };
    int myAtoi(string s, int i = 0) {

        // Skipping the leading whitespacces
        while (i < s.size() && s[i] == ' ')
            i++;

        // Determining the sign
        int sign = 1;
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            sign  = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // First recursive call
        return converter(s, i, 0, sign);
    }
};

// // //// Naive Approach //// //
// class Solution {
// public:
//     //  Helper function
//     bool alphanumeric(char c){
//         if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
//             return true;
//         else
//             return false;
//     }

//     int converter(string s, int n, int i){
//         string res = "";
//         while(i<n){

//             // Dealing with whitespaces
//             if(s[i] == ' '){
//                 i++;
//                 continue;
//             }

//             // Check for leading zeros
//             if(s[i] == '0'){
//                 i++;
//                 continue;
//             }

//             // Check for alphanumeric
//             if(alphanumeric(s[i]) || s[i] == '.')
//                 return 0;

//             if(s[i] == '-'){
//                 res+= s[i];
//                 i++;
//             }

//             if(s[i] >= '0' && s[i] <= '9') {
//                 res+= s[i];
//                 i++;
//             }
//         }

//         int ans = stoi(res);
//         if(ans<INT_MIN)return INT_MIN;
//         else if(ans>INT_MAX) return INT_MAX;
//         else return ans;
//     }

//     // Main function
//     int myAtoi(string s) {
//         int n = s.length();
//         int i = 1;
//         converter(s, n, i);
//         return 0;
//     }

// };