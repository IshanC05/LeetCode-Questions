class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int curr = 1;
        
        while(k){
            
            int l = 0, h = arr.size() - 1;
            
            bool flag = false;
            
            while(l <= h){
                
                int mid = l + (h - l) / 2;
                
                if(arr[mid] == curr){
                    
                    flag = true;
                    
                    break;
                }
                
                else if(arr[mid] > curr)   h = mid - 1;
                
                else    l = mid + 1;
                
            }
            
            if(!flag)   --k;
            
            ++curr;
            
        }
        
        return curr - 1;
        
    }
};