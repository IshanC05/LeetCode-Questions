class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        
        int cand = -1;
        
        int n = arr.size();
        
        double th = 0.25 * n;
        
        int i = 0;
        
        while(i < n){
            
            int j = i;
            
            while(j < n && arr[j] == arr[i])    ++j;
            
            if((j - i) > th)    cand = arr[i];
            
            i = j;
            
        }
        
        return cand;
        
    }
};