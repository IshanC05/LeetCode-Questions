class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>>ans(n, vector<int>(n, 0));
        
        int start = 1;
        
        int left = 0;
        int right = n - 1;
        int top = 0;
        int bottom = n - 1;
        
        while(left <= right && top <= bottom){
            
            for(int i = left; i <= right; i++){
                ans[top][i] = start++;
            }
            ++top;
            
            for(int i = top; i <= bottom; i++){
                ans[i][right] = start++;
            }
            --right;
            
            if(top <= bottom){
                for(int i = right; i >= left; i--){
                    ans[bottom][i] = start++;
                }
                --bottom;
            }
            
            if(left <= right){
                for(int i = bottom; i >= top; i--){
                    ans[i][left] = start++;
                }
                ++left;                
            }
        }
        
        return ans;
        
    }
};