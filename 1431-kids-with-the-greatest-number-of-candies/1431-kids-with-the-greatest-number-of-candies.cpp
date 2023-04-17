class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>ans(candies.size());
        int curMax = 0;
        for(int i : candies){
            curMax = max(i, curMax);
        }
        for(int i = 0;i < ans.size();i++){
            ans[i] = (candies[i] + extraCandies >= curMax) ? true : false;
        }
        return ans;
    }
};