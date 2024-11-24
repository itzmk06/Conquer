class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        // get sizes
        int rows = mat.size();
        int cols = mat[0].size();
        // rotate mat by 90 
        // get transpose
        for (int i = 0; i < rows; i++) {
            for (int j = i; j < cols; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        // reverse each row
        for (int i = 0; i < rows; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        // compare with target
        // only 3 rotations becuase after 4th rotation it gives back 0 degree 
        for(int i=0;i<4;i++){
            if(mat==target){
            return true;
            }
                rotate(mat);
        }
        return false;
    }
};
