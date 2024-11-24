class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // take transpose 
        int rows=matrix.size();
        int cols=matrix[0].size();
        // traverse whole 2D array 
        for(int i=0;i<rows;i++){
            for(int j=i;j<cols;j++){
                // swap m[i][j] with m[j][i]
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        // traverse each row and reverse it 
        for(int i=0;i<rows;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
