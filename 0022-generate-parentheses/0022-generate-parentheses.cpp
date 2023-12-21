class Solution {
public:
    void helper(string s, int left, int right, vector<string>&res){
        
        if(left == 0 && right == 0){
            res.push_back(s);
            return;
        }
        
        if(left > 0){
            
            helper(s + "(", left - 1, right, res);
            
        }
        
        if(right > left){
            
            helper(s + ")", left, right - 1, res);
            
        }
        
    }
    vector<string> generateParenthesis(int n) {
     
        vector<string>res;
        
        string input = "";
        
        helper(input, n, n, res);
        
        return res;
        
    }
};