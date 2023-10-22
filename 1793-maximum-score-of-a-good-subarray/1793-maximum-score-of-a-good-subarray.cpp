class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        int i = k;
        int j = k;
        int minE = nums[k];
        int res = nums[k];
        
        while(i > 0 || j < n - 1){
            
            int leftVal = (i > 0) ? nums[i - 1] : 0;
            int rightVal = (j < n - 1) ? nums[j + 1] : 0;
            
            if(leftVal > rightVal){
                --i;
                minE = min(minE, nums[i]);
            }else{
                ++j;
                minE = min(minE, nums[j]);
            }
            
            res = max(res, (j - i + 1) * minE);
        }
        
        return res;   
    }
};