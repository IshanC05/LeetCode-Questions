class Solution {
public:
    
    int helper(int n){
        
        long long res = 0;
        
        while(n){
            
            int rem = n % 10;
            
            n = n / 10;
            
            res += (rem * rem);
            
        }
        
        return res;
        
    }
    
    bool isHappy(int n) {
        
        if(n == 1)  return true;
        
        unordered_map<int,bool>mp;
        
        mp[n] = true;
        
        while(true){
            
            n = helper(n);
            
            if(n == 1)  return true;
            
            if(mp.count(n))     break;
            
            mp[n] = true;
            
        }
        
        return false;

    }
};