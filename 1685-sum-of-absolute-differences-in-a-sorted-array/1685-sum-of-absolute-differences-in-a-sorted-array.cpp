class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        
        int n = nums.size(), lsum = 0, rsum = 0;
        
        for(int i = n - 1; i >= 0; i--)
            rsum += nums[i];
        
        vector<int>res(n);
        
        for(int i = 0; i < n; i++){
            
            rsum -= nums[i];
            
            res[i] += abs(lsum - (nums[i] * i));
            
            res[i] += abs(rsum - (nums[i] * (n - 1 - i)));
            
            lsum += nums[i];
            
        }
        
        return res;
        
    }
};