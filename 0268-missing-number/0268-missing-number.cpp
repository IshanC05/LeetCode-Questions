class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        
        int expectedSum = (n * (n + 1)) / 2;
        int currSum = 0;
        
        for(int i : nums)
            currSum = currSum + i;
        
        return expectedSum - currSum;
    }
};