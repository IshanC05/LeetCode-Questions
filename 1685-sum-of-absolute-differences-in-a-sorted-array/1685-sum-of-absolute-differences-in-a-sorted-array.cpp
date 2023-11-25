class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int>lsum(n, 0), rsum(n, 0);
        
        for(int i = 1; i < n; i++){
            lsum[i] = lsum[i - 1] + nums[i - 1];   
        }
        
        for(int i = n - 2; i >= 0; i--){
            rsum[i] = rsum[i + 1] + nums[i + 1];
        }
        
        vector<int>res(n);
        
        for(int i = 0; i < n; i++){
            
            res[i] += abs(lsum[i] - (nums[i] * i));
            
            res[i] += abs(rsum[i] - (nums[i] * (n - 1 - i)));
            
        }
        
        return res;
        
    }
};