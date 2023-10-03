class Solution {
public:
    string convertToTitle(int n) {
        
        string ans = "";
        
        while(n){
            
            char d = ((n - 1) % 26) + 'A';
            
            ans.push_back(d);
            
            n = (n - 1) / 26;            
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};