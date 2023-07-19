class Solution {
public:
    
    bool canBreak(string &a, string &b){
        
        bool ans = true;
        
        for(int i = 0; i < a.size(); i++){
            
            if(a[i] < b[i]) return false;
            
        }
        
        return ans;
    }
    
    bool checkIfCanBreak(string s1, string s2) {
        
        sort(s1.begin(), s1.end());
        
        sort(s2.begin(), s2.end());
        
        return (canBreak(s1, s2) || canBreak(s2, s1));
        
    }
};