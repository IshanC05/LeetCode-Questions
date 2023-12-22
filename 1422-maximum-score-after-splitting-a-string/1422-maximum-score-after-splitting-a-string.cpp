class Solution {
public:
    int maxScore(string s) {
        
        int count1s = 0, count0s = 0;
        
        for(char i : s)     
            if(i == '1')    ++count1s;
        
        int res = 0;
        
        for(int i = 0; i < s.size() - 1; i++){
            
            if(s[i] == '0')     ++count0s;
            
            if(s[i] == '1')     --count1s;
            
            res = max(res, count1s + count0s);            
        }
        
        return res;        
    }
};