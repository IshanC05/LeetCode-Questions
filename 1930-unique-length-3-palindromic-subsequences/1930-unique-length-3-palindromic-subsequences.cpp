class Solution {
public:
    int countPalindromicSubsequence(string s) {
        
        unordered_map<char, pair<int,int>>indexes;
        
        for(int i = 0; i < 26; i++){
            
            int start = -1, end = -1;
            
            char t = (char)(i + 'a');
            
            for(int j = 0; j < s.size(); j++){
                
                if(s[j] == t){
                    
                    if(start == -1)     start = j;
                    
                    end = j;
                    
                }
                
            }
            
            if(start != -1)     
                indexes[t] = {start, end};
            
        }
        
        unordered_set<string>ans;
        
        for(auto it : indexes){
            
            char a = it.first, c = a;
            
            int l = it.second.first, r = it.second.second;
            
            for(int k = l + 1; k < r; k++){
                
                string t{a, s[k], c};
                
                ans.insert(t);
                
            }
        }
        
        return ans.size();
    }
};