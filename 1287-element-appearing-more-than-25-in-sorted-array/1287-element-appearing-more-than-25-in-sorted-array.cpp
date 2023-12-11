class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        
        int count = 0, cand = -1;
        
        int n = arr.size();
        
        double th = 0.25 * n;
        
        int i = 0;
        
        while(i < n){
            
            int j = i;
            
            while(j < n && arr[j] == arr[i]){
                
                ++count; 
                
                ++j;
                
            }
            
            if(count > th)  cand = arr[i];
            
            count = 0;
            
            i = j;
            
        }
        
        return cand;
        
    }
};