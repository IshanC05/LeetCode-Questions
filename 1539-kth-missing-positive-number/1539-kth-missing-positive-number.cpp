class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        vector<int>freq(1001, false);
        
        for(int i : arr)    freq[i] = true;
        
        for(int i = 1; i < 1001; i++){
            
            if(!freq[i])    --k;
            
            if(!k)  return i;
            
        }
        
        int i = 1000;
        
        while(k)  --k, i++;
        
        return i;
    }
};