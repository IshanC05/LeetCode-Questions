class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg = 0, zero = 0, n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                ++zero;
            }else if(nums[i] < 0){
                ++neg;
            }
        }
        if(zero > 0){
            return 0;
        }else if(neg % 2 == 0){
            return 1;
        }
        return -1;
    }
};