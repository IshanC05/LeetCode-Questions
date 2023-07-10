class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        vector<string>arr;
        
        int i = 0, n = s.size();
        
        while(i < n){
            
            string t = "";
            
            while(i < n && s[i] != ' '){
                
                t.push_back(s[i++]);
                
            }
            
            if(t != "") arr.push_back(t);
            
            ++i;
            
        }
        
        if(arr.size() != pattern.size())    return false;
        
        unordered_map<char, string>mp1;
        unordered_map<string, char>mp2;
        
        for(int i = 0; i < pattern.size(); i++){
            
            if(mp1.find(pattern[i]) != mp1.end()){
                
                if(mp1[pattern[i]] != arr[i])    return false;
                
            }
            
            if(mp2.find(arr[i]) != mp2.end()){
                
                if(mp2[arr[i]] != pattern[i])   return false;
                
            }
            
            mp1[pattern[i]] = arr[i];
            mp2[arr[i]] = pattern[i];
            
        }
        
        return true;
        
    }
};