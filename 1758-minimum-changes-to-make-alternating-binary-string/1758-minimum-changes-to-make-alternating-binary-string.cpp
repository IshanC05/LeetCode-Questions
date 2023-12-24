class Solution {
public:
    int steps(string s, int n, int digit){
        
        int ans = 0;
        
        for(char x : s){
            
            if((x - '0') != digit)  ++ans;
            
            digit = 1 - digit;
            
        }
        
        return ans;
        
    }
    int minOperations(string s) {
        
        int n = s.size(), res = INT_MAX;
        
        res = min(res, steps(s, n, 0));
        
        res = min(res, steps(s, n, 1));
        
        return res;
        
    }
};