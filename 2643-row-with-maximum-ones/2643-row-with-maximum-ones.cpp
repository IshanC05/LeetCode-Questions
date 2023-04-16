class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        // vector<int>ans;
        int row=0, maxCount=0;
        for(int i=0;i<mat.size();i++){
            int count1 = 0;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j] == 1){
                    ++count1;
                }
            }
            if(count1 > maxCount){
                row = i;
                maxCount = count1;
            }
        }
        return {row, maxCount};
    }
};