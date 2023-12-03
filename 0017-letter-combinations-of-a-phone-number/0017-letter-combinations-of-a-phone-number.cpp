class Solution {
public:
    string getStringByDigit(char c){
        
        switch(c){
            case '2' : return "abc";
            case '3' : return "def";
            case '4' : return "ghi";
            case '5' : return "jkl";
            case '6' : return "mno";
            case '7' : return "pqrs";
            case '8' : return "tuv";
            case '9' : return "wxyz";
        }
        
        return "";
    }
    
    void helper(string input, int n, vector<string>&res){
        
        if(input.size() == 0){
            res.push_back("");
            return;
        }
        
        char firstDigit = input[0];
        
        helper(input.substr(1), n, res);
        
        int K = res.size();
        
        string toBeAdded = getStringByDigit(firstDigit);
        
        int copies = toBeAdded.size() - 1;
        
        for(int i = 0; i < copies; i++){
            
            for(int j = 0; j < K; j++)  res.push_back(res[j]);
            
        }
        
        int newSize = res.size(), l = 0;
        
        for(int i = 0; i < toBeAdded.size(); i++){
            
            string newS(1, toBeAdded[i]);
            
            for(int j = 0; j < K; j++){
                
                res[l] = newS + res[l];
                
                ++l;
                
            }
            
        }
        
        return;
        
    }
    
    vector<string> letterCombinations(string digits) {
        
        string output = "";
        
        int n = digits.size();
        
        vector<string>res;
        
        helper(digits, n, res);
        
        if(res.size() == 1)     res.clear();
        
        return res;
    }
};