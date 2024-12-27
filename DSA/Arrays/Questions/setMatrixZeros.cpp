// * bruteforce 
class Solution {
public:
    void putZeros(vector<vector<int>>&matrix,int row,int col){
        // set rows to 0 
        for(int i=0;i<matrix[0].size();i++){
            matrix[row][i]=0;
        }
        // set cols to 0 
        for(int j=0;j<matrix.size();j++){
            matrix[j][col]=0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int>target;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    target.push_back(i);
                    target.push_back(j);
                }
            }
        }
        if(target.size()<1){
            return;
        }
        for(int i=0;i<target.size()-1;i+=2){
            int row=target[i];
            int col=target[i+1];
            putZeros(matrix,row,col);
        }
    }
};
