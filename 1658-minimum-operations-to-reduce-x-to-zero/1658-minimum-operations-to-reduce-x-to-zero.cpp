class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int totalSum = 0, n = nums.size();
        
        for(int i : nums)
            totalSum += i;
        
        int targetSum = totalSum - x;
        
        if(targetSum < 0)   return -1;
        
        if(targetSum == 0)  return n;
        
        int i = 0, j = 0, maxWindowLength = 0, currWindowSum = 0;
        
        while(j < n){
            
            currWindowSum += nums[j];
            
            while(currWindowSum > targetSum){
                currWindowSum -= nums[i++];
            }
            
            if(currWindowSum == targetSum){
                maxWindowLength = max(maxWindowLength, j - i + 1);
            }
            
            ++j;
            
        }
        
        return maxWindowLength == 0 ? -1 : n - maxWindowLength;
        
    }
};