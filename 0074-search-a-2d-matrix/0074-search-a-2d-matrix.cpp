class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
     
        int rows = matrix.size(), cols = matrix[0].size();
        
        int l = 0, h = (rows * cols) - 1;
        
        while(l <= h){
            
            int mid = l + (h - l) / 2;
            
            int candidate = matrix[mid / cols][mid % cols];
            
            if(candidate == target)     return true;
            
            else if(candidate > target)     h = mid - 1;
            
            else    l = mid + 1;
            
        }
        
        return false;
        
    }
};