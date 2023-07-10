class Solution {
public:
    
    int bSearch(vector<int>&arr, long long start, long long target){
        
        long long n = arr.size(), l = 0, h = n - 1, idx = -1;
        
        while(l <= h){
            
            int mid = l + (h - l) / 2;
            
            long long prod = start * arr[mid];
            
            if(prod >= target){
                idx = mid;
                h = mid - 1;
            }else{
                l = mid + 1;
            }
            
        }
        
        return idx == -1 ? 0 : n - idx;
        
    }
    
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        sort(potions.begin(), potions.end());
        
        vector<int>ans(spells.size());
        
        for(int i = 0; i < spells.size(); i++){
            
            ans[i] = bSearch(potions, spells[i], success);
            
        }
        
        return ans;
        
    }
};