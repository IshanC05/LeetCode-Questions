class Solution {
public:
    string reverseWords(string s) {
        
        vector<string>str;
        
        string s1 = "";
        
        int i = 0;
        
        while(i < s.size()){
            if(s[i] != ' ')     s1.push_back(s[i]);
            
            else{
                if(!s1.empty()){
                    str.push_back(s1);
                }
                s1 = "";
            }
            
            ++i;
        }
        
        if(!s1.empty())     str.push_back(s1);
        
        string ans = "";
        
        for(int i = 0; i < str.size(); i++){
            string v = str[i];
            reverse(v.begin(), v.end());
            ans = ans + v;
            if(i != str.size() - 1)     ans.push_back(' ');
        }
        return ans;
        
    }
};