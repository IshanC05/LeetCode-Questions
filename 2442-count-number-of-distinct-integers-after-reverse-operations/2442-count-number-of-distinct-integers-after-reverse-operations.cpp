class Solution {
public:
    int rev(int num){
        if(num < 10)    return num;
        
        int ans = 0;
        
        while(num){
            ans = (ans * 10) + (num % 10);
            num = num / 10;
        }
        
        return ans;
    }
    int countDistinctIntegers(vector<int>& nums) {
        
        unordered_set<int>freqSet(nums.begin(), nums.end());
        
        for(int i : nums){
            int k = rev(i);
            freqSet.insert(k);
        }
        
        return freqSet.size();
    }
};