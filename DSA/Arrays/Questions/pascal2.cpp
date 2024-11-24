// * Bruteforce 
class Solution {
public:
    vector<int> getRow(int rowIndex) {
            vector<vector<int>>result(34);
            for(int i=0;i<=33;i++){
                vector<int>temp(i+1,1);
                for(int j=1;j<i;j++){
                    temp[j]=result[i-1][j]+result[i-1][j-1];
                }
                    result[i]=temp;
            }
            return result[rowIndex];
    }
};
