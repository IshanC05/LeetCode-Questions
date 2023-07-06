class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int r = matrix.size(), c = matrix[0].size(), l = 0, h = (r * c) - 1;
        
        while(l <= h){
            
            int mid = (l + h) / 2;
            
            int element = matrix[mid / c][mid % c];
            
            if(element == target){
                return true;
            }else if(element > target){
                h = mid - 1;
            }else{
                l = mid + 1;
            }
            
        }
        
        return false;
        
    }
};