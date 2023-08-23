class Solution {
public:
    int minimumPartition(string s, int k) {
        
        long long num = 0, ans = 1;
        
        for(int i = 0; i < s.size(); i++){
            
            num = (num * 10) + s[i] - '0';
            
            if(num > k){
                
                num = s[i] - '0';
                
                ++ans;
                
            }
            
            if(num > k){
                
                return -1;
                
            }
            
        }
        
        return ans;
        
    }
};