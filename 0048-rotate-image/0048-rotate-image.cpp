// // //// BRUTE //// //
// // WE create an ans matrix with all zeros(n*n)
// // It passes all the test cases but has SC:O(n^2)
// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         // assigning the n rows and n cols with all zeroes
//         vector<vector<int>> ans(n, vector<int>(n,0));

//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < n; j++){
//                 // each i will become j and j will become n-1-i after rotstion 
//                 ans[j][n-1-i] = matrix[i][j];
//             }
//         }
//         // Reassign ans to matrix
//         matrix = ans;
        
//     }
// };



// //// OPTIMAL //// //
// WE can do it by taking TRANSPOSE then REVERSING each row
// For Transpose: We need to swap diagonally opposite elements in both halves
// while the primary diagonal elements remain where they are

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Transpose
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse each row
        for(int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};