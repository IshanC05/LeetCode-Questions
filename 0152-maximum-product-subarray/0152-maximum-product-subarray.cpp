class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res = INT_MIN, left = 1, right = 1;
        
        for(int i = 0; i < n; i++){
            left = left * nums[i];
            right = right * nums[n - i - 1];
            
            res = max({left, right, res});
            
            left = (left == 0 ? 1 : left);
            right = (right == 0 ? 1 : right);
        }
        
        return res;
    }
};