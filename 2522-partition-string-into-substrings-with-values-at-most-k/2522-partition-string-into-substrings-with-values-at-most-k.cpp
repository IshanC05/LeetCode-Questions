class Solution {
public:
    int minimumPartition(string s, int k) {
        
        string sub = "";
        
        int ans = 1;
        
        for(int i = 0; i < s.size(); i++){
            
            sub.push_back(s[i]);
            
            long long num = stoll(sub);
            
            if(num <= k){
                
//                 do nothing
                
            }else{
                
                sub = "";
                
                sub.push_back(s[i]);
                
                ++ans;
                
                if(sub.size() == 1 && (sub[0] - '0' > k))   return -1;
            }
               
        }
        
        return ans;
        
    }
};