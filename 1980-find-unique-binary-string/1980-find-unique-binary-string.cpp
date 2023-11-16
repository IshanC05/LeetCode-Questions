class Solution {
public:
    bool helper(string input, int n, string &res, unordered_set<string>&seen){
        
        if(res.size() != 0)     return true;
        
        if(n == 0){
            
            if(seen.find(input) != seen.end())  return false;
            
            res = input;
            
            return true;            
        }
        
        bool addZero = false, addOne = false;
        
        addZero = helper(input + '0', n - 1, res, seen);
        
        if(!addZero)
            addOne = helper(input + '1', n - 1, res, seen);
        
        
        return (addZero || addOne);
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        
        int n = nums.size();
        
        string res = "";
        
        unordered_set<string>present(nums.begin(), nums.end());
        
        helper("", n, res, present);
        
        return res;        
    }
};