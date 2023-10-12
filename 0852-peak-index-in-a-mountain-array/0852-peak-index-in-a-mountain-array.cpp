class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int l = 0, r = arr.size() - 1;
        
        while(l <= r){
            
            int m = l + (r - l) / 2;
            
            if(arr[m] > arr[m + 1]){
                
                if(arr[m] > arr[m - 1])     return m;
                
                else    r = m - 1;
            }     
            
            else    l = m + 1;
        }
        
        return -1;
        
    }
};