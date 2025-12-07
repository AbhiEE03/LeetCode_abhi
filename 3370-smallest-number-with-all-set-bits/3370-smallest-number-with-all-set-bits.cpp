class Solution {
public:

    int smallestNumber(int n) {
        
        long long result=n;
        while(( result & (result + 1)) !=0 ){
            result++;
        }
        return result;
    }
};




// //////// Approach -1 (TLE) /////// //

/* Convert n to binary then check if all bits are 1. if all are 1 then return a otherwise incremnet n*/

// class Solution {
// public:

//     string to_Binary(int a,string binary ){
       
//         while(a!=1){
//             if(a%2==1) binary+="1";
//             else binary+="0";
//         }
//         return binary;
//     }

//     int smallestNumber(int n) {
//         int a=n;

//         while(true){
//             string binary="";
//             to_Binary(a, binary);
//             int length=binary.size();

//             for(int i=0; i<length; i++){
//                 if(binary[i]==1)continue;
//                 else {
//                     a++;
//                     break;
//                 };
//                 return a;
//             }
//         }
//         return a;
//     }
// };