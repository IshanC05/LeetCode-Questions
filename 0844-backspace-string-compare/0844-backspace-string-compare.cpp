class Solution {
public:
    string helper(string s){
        
        string ans = "";
        
        for(int i = 0; i < s.size(); i++){
            
            if(s[i] == '#'){
                
                if(!ans.empty())    ans.pop_back();
                
                else    continue;
            }
            
            else    ans.push_back(s[i]);
        }
        
        return ans;
        
    }
    
    bool backspaceCompare(string s, string t) {
        
        string s1 = helper(s);
        string s2 = helper(t);
        
        cout << s1 << " " << s2;
        return s1 == s2;        
    }
};