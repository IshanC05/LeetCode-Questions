class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        unordered_map<int,int>freq, used;
        
        int ans = 0;
        
        for(int i : nums)   ++freq[i];
        
        for(int i = 0; i < nums.size(); i++){
            
            int a = nums[i];
            
            int b = k - nums[i];
            
            if(used[a] == 0 && used[b] == 0){
                
                if(a == b){
                    
                    ans += freq[nums[i]] / 2;
                    
                }else{
                    
                    ans += min(freq[a], freq[b]);
                }
                
            }
            
            used[a] = 1;
            
            used[b] = 1;
            
        }
        
        return ans;
        
    }
};