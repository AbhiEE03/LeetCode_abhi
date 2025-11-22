

class Solution
{
public:
    int celebrity(vector<vector<int>> &M){
        int top =0, bottom=M.size()-1;
        while(top<bottom){
            if(M[top][bottom]==1) top++;
            else if(M[bottom][top]==1) bottom--;
            else {
                top++;
                bottom--;
            }
        }
        if(top>bottom) return -1;
        for(int i=0;i<M.size();i++){
            if(i==top) continue;
            if(M[top][i]==0 && M[i][top]==1)continue;
            else return -1;
        }
        return top;
        
    }
};
