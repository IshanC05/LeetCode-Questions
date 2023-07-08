class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int>ans(n + 1, 0);
        
        for(int i = 1; i < n + 1; i++){
            
            int num = i;
            
            int smallAns = 0, mask = 1;
            
            while(num){
                
                smallAns = (mask & num) ? ++smallAns : smallAns;
                
                num = (num >> 1);
                
            }
            
            ans[i] = smallAns;
        }
        
        return ans;
        
    }
};