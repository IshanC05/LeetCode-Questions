class Solution {
public:
    
    bool helper(vector<int>&arr, int k){
        
        int l = 0, h = arr.size() - 1;
        
        while(l <= h){
            
            int mid = l + (h - l) / 2;
            
            if(arr[mid] == k)   return true;
            
            else if(arr[mid] < k)   l = mid + 1;
            
            else h = mid - 1;
            
        }
        
        return false;
        
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int rows = matrix.size(), cols = matrix[0].size();
        
        bool found = false;
        
        for(int i = 0; i < rows; i++){
            
            found = helper(matrix[i], target);
            
            if(found)   break;
            
        }
        
        return found;
        
    }
};