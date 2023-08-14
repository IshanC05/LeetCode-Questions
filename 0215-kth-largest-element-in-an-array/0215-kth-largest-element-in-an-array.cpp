class Solution {
public:
    int partition(vector<int>&arr, int l, int r, int pivot){
        
        int i = l, j = l;
        
        while(i <= r){
            
            if(arr[i] <= pivot){
                
                swap(arr[i], arr[j++]);
                
            }
            
            ++i;
            
        }
        
        return j - 1;
        
    }
    
    int quickSelect(vector<int>&arr, int l, int r, int k){
        
        if(l > r)   return -1;
        
        int pivot = arr[r];
        
        int pivotIdx = partition(arr, l, r, pivot);
        
        if(pivotIdx == k)   return arr[pivotIdx];
        
        else if(pivotIdx > k)   return quickSelect(arr, l, pivotIdx - 1, k);
        
        return quickSelect(arr, pivotIdx + 1, r, k);
        
    }
    
    
    int findKthLargest(vector<int>& nums, int k) {
        
        k = (nums.size() - k);
        
        return quickSelect(nums, 0, nums.size() - 1, k);
        
    }
};