class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int>st(nums.begin(), nums.end());
        
        int n = nums.size();
        
        int expectedSum = (n * (n + 1)) / 2;
        
        int uniqueSum = 0, arraySum = 0;
        
        for(int i : nums)
            arraySum += i;
        
        for(auto it : st)
            uniqueSum += it;
        
        int missing = expectedSum - uniqueSum;
        int duplicate = arraySum - uniqueSum;
        
        return {duplicate, missing};
    }
};