class Solution {
public:
    string removeKdigits(string num, int k) {
        
        string ans = "";
        
        int numsToKeep = num.size() - k, i = 0;
        
        for(; i < num.size(); i++){
            
            while(!ans.empty() && ans.back() > num[i] && (ans.size() + num.size() - i) > numsToKeep){
                
                ans.pop_back();
                
            }
            
            if(ans.size() < numsToKeep)     ans.push_back(num[i]);
            
        }
        
        i = 0;
        
        while(i < ans.size() && ans[i] == '0')  ++i;
        
        ans = ans.substr(i);
        
        return (ans == "") ? "0" : ans;
    }
};