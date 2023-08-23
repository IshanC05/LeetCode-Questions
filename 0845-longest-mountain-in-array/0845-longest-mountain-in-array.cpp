class Solution {
public:
    int longestMountain(vector<int>& arr) {
        
        int n = arr.size(), ans = 0;
        
        if(n < 3)   return ans;
        
        for(int i = 1; i < n - 1;){
            
            if(arr[i] > arr[i - 1] && arr[i] > arr[i + 1]){
                
                int count = 1;
                
                int j = i, k = i;
                
                while(j > 0  && arr[j] > arr[j - 1])    --j, ++count;
                
                while(k < n - 1 && arr[k] > arr[k + 1]) ++k, ++count;
                
                ans = max(ans, count);
                
                i = k;
                
            }
            
            else    ++i;
            
        }
        
        return ans;
        
    }
};