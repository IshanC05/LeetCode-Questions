class Solution {
public:
    
    bool bSearch(vector<int>&arr, int l, int h, int target){
        
        while(l <= h){
            
            int mid = l + (h - l) / 2;
            
            if(arr[mid] == target)  return true;
            
            else if(arr[mid] > target)  h = mid - 1;
            
            else    l = mid + 1;
            
        }
        
        return false;
        
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row = matrix.size(), col = matrix[0].size();
        
        bool found = false;
        
        for(int i = 0; i < row; i++){
                
            found = bSearch(matrix[i], 0, col - 1, target);
            
            if(found)   break;
            
        }
        
        return found;
    }
};