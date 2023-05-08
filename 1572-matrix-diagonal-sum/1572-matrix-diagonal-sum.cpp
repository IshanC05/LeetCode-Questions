class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int lsum = 0, rsum = 0;
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[i].size(); j++){
                if(i == j){
                    lsum = lsum + mat[i][j];
                }
                if(i + j + 1 == mat.size()){
                    rsum = rsum + mat[i][j];
                }
            }
        }
        int mid = mat.size() / 2;
        if(mat.size() % 2 != 0){
            return lsum + rsum -  mat[mid][mid];
        }
        return lsum + rsum;
    }
};