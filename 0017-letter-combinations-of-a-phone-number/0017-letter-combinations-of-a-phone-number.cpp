class Solution {
public:
    
    unordered_map<char,string>mp;
    
    vector<string>ans;
    
    string getChar(char a){
        
        if(mp.empty()){
            
            mp.insert(make_pair('2', "abc"));
            mp.insert(make_pair('3', "def"));
            mp.insert(make_pair('4', "ghi"));
            mp.insert(make_pair('5', "jkl"));
            mp.insert(make_pair('6', "mno"));
            mp.insert(make_pair('7', "pqrs"));
            mp.insert(make_pair('8', "tuv"));
            mp.insert(make_pair('9', "wxyz"));    
        }
        
        return mp[a];
        
    }
    
    void helper(string input){
        
        if(input.size() == 0){
            
            ans.push_back("");
            
            return;
            
        }
        
        char curr = input[0];
        
        helper(input.substr(1));
        
        int smallSize = ans.size();
        
        string options = getChar(curr);
        
        for(int i = 0; i < options.size() - 1; i++){
            
            for(int j = 0; j < smallSize; j++){
                
                ans.push_back(ans[j]);
                
            }
        
        }
        
        int k = 0;
        
        for(int i = 0; i < options.size(); i++){
            
            for(int j = 0; j < smallSize; j++){
                
                ans[k] = options[i] + ans[k];
                
                ++k;
            }
            
        }
        
           
        return;        
    }
    
    vector<string> letterCombinations(string digits) {
        
        helper(digits);
        
        if(ans.size() < 3)     ans.clear();
        
        return ans;
        
    }
};