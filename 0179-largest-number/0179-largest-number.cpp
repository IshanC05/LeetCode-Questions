class Solution {
public:
    bool static cmp(string a, string b) {
        
        return (a + b) > (b + a);
    
    }

    string largestNumber(vector<int>& nums) {
        
        vector<string>strNums;
        
        for(int i : nums)   strNums.push_back(to_string(i));
        
        sort(strNums.begin(), strNums.end(), cmp);
        
        if (strNums[0] == "0") return "0";
        
        string ans = "";
        
        for(string x : strNums)     ans += x;
        
        return ans;
    }
};