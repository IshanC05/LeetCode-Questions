class Solution {
public:
    int revCalculate(int n){
        
        int res = 0;
        
        while(n){
            
            int rem = n % 10;
            
            res = (res * 10) + rem;
            
            n = n / 10;
            
        }
        
        return res;
        
    }
    
    int countNicePairs(vector<int>& nums) {
        
        int n = nums.size(), mod = 1e9+7;
        
        unordered_map<int, int>revCount;
        
        for(int i = 0; i < n; i++){
            
            int num = nums[i];
            
            int revNum = revCalculate(num);
            
            int diff = num - revNum;
            
            ++revCount[diff];
            
        }
        
        long long res = 0;
        
        for(auto it : revCount){
            
            // cout << it.first << " " << it.second << "\n";
            
            long long count = it.second - 1;
            
            long long pairs = (count * (count + 1)) / 2;
            
            res = (res + pairs) % mod;
            
        }
        
        return res;
    }
};