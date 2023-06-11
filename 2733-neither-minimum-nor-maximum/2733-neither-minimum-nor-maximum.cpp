class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int maxe = nums[0], mine = nums[0];
        for(int i : nums){
            maxe = max(maxe, i);
            mine = min(mine, i);
        }
        
        int res = -1;
        
        for(int i : nums){
            if(i != maxe and i != mine){
                res = i;
                break;
            }
        }
        
        return res;
    }
};