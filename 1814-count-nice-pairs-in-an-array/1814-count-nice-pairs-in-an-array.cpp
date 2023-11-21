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
        
        long long res = 0;
        
        for(int i = 0; i < n; i++){
            
            int num = nums[i];
            
            int revNum = revCalculate(num);
            
            int diff = num - revNum;
            
            res = (res + revCount[diff]) % mod;
            
            ++revCount[diff];
            
        }
        
        return res;
    }
};