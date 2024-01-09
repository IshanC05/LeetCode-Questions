class Solution {
public:
    static bool cmp(string &a, string &b){
        if(a.length() != b.length())    return a.length() < b.length();
        
        return a < b;
    }
    
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), cmp);
        return nums[nums.size() - k];
    }
};