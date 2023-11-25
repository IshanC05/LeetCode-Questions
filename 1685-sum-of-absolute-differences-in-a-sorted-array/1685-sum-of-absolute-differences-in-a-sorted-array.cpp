class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        
        int n = nums.size(), totalSum = 0;
        
        vector<int>lsum(n, 0), rsum(n, 0);
        
        for(int i = 1; i < n; i++){
            
            lsum[i] = lsum[i - 1] + nums[i - 1];
            
        }
        
        for(int i = n - 2; i >= 0; i--){
            
            rsum[i] = rsum[i + 1] + nums[i + 1];
                        
        }
        
        totalSum += nums[0];
        
        vector<int>res(n);
        
        for(int i = 1; i < n - 1; i++){
            
            int leftSum = abs(lsum[i] - (nums[i] * (i)));
            
            int rightSum = abs(rsum[i] - (nums[i] * (n - 1 - i)));
            
            res[i] = leftSum + rightSum;
            
            totalSum += nums[i];
            
        }
        
        totalSum += nums[n - 1];
        
        res[0] = abs(totalSum - (nums[0] * n));
        
        res[n - 1] = abs(totalSum - (nums[n - 1] * n));
        
        return res;
        
    }
};