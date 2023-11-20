class Solution {
public:
    long long minimumSteps(string s) {
        
        long long res = 0;
        
        int ones = 0;
        
        for(char i : s){
            
            if(i == '1')    ++ones;
            
            else    res += ones;
            
        }
        
        return res;
        
    }
};