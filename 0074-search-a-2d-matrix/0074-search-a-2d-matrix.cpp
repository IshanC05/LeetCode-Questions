class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int rows = matrix.size(), col = matrix[0].size();
        
        int l = 0, h = (rows * col) - 1;
        
        while(l <= h){
            
            int mid = l + (h - l) / 2;
            
            int elem = matrix[mid / col][mid % col];
            
            if(elem == target)  return true;
            
            else if(elem > target)  h = mid - 1;
            
            else l = mid + 1;
            
        }
        
        return false;
        
    }
};