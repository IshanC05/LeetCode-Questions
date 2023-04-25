class Solution {
public:
    int lastIdx(vector<int>nums, int target){
        int l = 0, h = nums.size() - 1, ans = -1;
        while(l <= h){
            int mid = l + (h - l) / 2;
            if(nums[mid] > target){
                h = mid - 1;
            }else if(nums[mid] < target){
                l = mid + 1;
            }else{
                if(mid == nums.size() - 1 || nums[mid] != nums[mid + 1]){
                    return mid;
                }else{
                    l = mid + 1;
                }
            }
        }
        return ans;
    }
    int firstIdx(vector<int>nums, int target){
        int l = 0, h = nums.size() - 1, ans = -1;
        while(l <= h){
            int mid = l + (h-l)/2;
            if(nums[mid] < target){
                l = mid + 1;
            }else if(nums[mid] > target){
                h = mid - 1;
            }else{
                if(mid == 0 || nums[mid] != nums[mid -1]){
                    return mid;
                }else{
                    h = mid - 1;
                }
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans({-1, -1});
        ans[0] = firstIdx(nums, target);
        if(ans[0] == -1){
            ans[1] = -1;
        }else{
            ans[1] = lastIdx(nums, target);
        }
        return ans;
    }
};