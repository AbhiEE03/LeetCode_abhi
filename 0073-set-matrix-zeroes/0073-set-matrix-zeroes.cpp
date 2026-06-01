// // //// BRUTE //// //

// class Solution {
// public:

//     // Assigns 'a' (Any value other than the range of matrix elements) to the entire row
//     void rowZero(int i, vector<vector<int>>& matrix, int r, int c){
//         for(int j=0; j<c; j++){
//             if(matrix[i][j]!=0)
//                 matrix[i][j]='a';
//         }
//     }

//     // Assigns 'a' (Any value other than the range of matrix elements) to the entire col
//     void colZero(int j, vector<vector<int>>& matrix, int r, int c){
//         for(int i=0; i<r; i++){
//             if(matrix[i][j]!=0)
//                 matrix[i][j]='a';
//         }
//     }

//     void setZeroes(vector<vector<int>>& matrix) {
//         int r = matrix.size(); // ROw Size
//         int c = matrix[0].size(); // Col Size


//         // Checking which positions have ZERO from the beginning
//         for(int i = 0; i<r; i++){
//             for(int j =0 ; j<c; j++){
//                 if(matrix[i][j] == 0){
//                     rowZero(i, matrix, r, c);
//                     colZero(j, matrix, r, c);
//                 }
//             }
//         }

//         // Replace all the 'a' with ZERO which will give us the final matrix
//         for(int i = 0; i<r; i++){
//             for(int j =0 ; j<c; j++){
//                 if(matrix[i][j] == 'a'){
//                     matrix[i][j] = 0;
//                 }
//             }
//         }

//     }

    
// };


// //// Better //// //

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // GEt the nos of rows and cols
        int r = matrix.size();
        int c = matrix[0].size();

        // int row[r] = {0};
        // int col[c] = {0};
        vector<int> row(r, 0);
        vector<int> col(c, 0);

        // For each ZERO mark 1 in the row and col array
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(matrix[i][j] == 0){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }


        // Whenever the row or col has 1, mark the corresponding matrix element as ZERO
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(row[i]==1 || col[j]==1){
                    matrix[i][j] = 0;
                }
            }
        }
    }

};