class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // create a 2D vector 
        vector<vector<int>>result(numRows);
        // we know how many rows should be there 
        for(int i=0;i<numRows;i++){
            // now create a vector of i+1 cols each time for each row 
            vector<int>temp(i+1,1);
            for(int j=1;j<i;j++){
                // take previous row same col element with previous row previous col element 
                temp[j]=result[i-1][j]+result[i-1][j-1];
            }
            // replace that row of result with temp 
                result[i]=temp;
        }
        return result;
    }
};
