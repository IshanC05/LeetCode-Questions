class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        
        int cand = -1;
        
        int n = arr.size();
        
        int i = 0;
        
        while(i < n){
            
            int j = i;
            
            while(j < n && arr[j] == arr[i])    ++j;
            
            if((j - i) > n / 4)    cand = arr[i];
            
            i = j;
            
        }
        
        return cand;
        
    }
};