class Solution {
public:
    vector<int> getDigits(int n){
        
        string t = to_string(n);
        char a = t[0];
        char b = t[t.size() - 1];
        int x = a - '0';
        int y = b - '0';
        return {x, y};
        
    }
    
    int countBeautifulPairs(vector<int>& nums) {
        
        vector<vector<int>>digits;
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            vector<int>temp = getDigits(nums[i]);
            digits.push_back(temp);
        }
        
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                ans = (__gcd(digits[i][0], digits[j][1]) == 1) ? ++ans : ans;
            }
        }
        
        return ans;
    }
};