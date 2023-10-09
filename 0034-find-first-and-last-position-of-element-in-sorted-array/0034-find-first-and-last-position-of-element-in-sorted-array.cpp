class Solution {
public:
    vector<int> helper(vector<int>& nums, int target, bool pos) {
        int l = 0, h = nums.size() - 1;
        int ans = -1;

        while (l <= h) {
            int m = l + (h - l) / 2;

            if (nums[m] == target) {
                ans = m;

                if (pos) {
                    if (m > 0 && nums[m - 1] == target) {
                        h = m - 1;
                    } else {
                        break;
                    }
                } else {
                    if (m < nums.size() - 1 && nums[m + 1] == target) {
                        l = m + 1;
                    } else {
                        break;
                    }
                }
            } else if (nums[m] < target) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }

        return {ans, ans};
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) {
            return {-1, -1};
        }

        vector<int> result(2, -1);

        vector<int> first = helper(nums, target, true);
        vector<int> last = helper(nums, target, false);

        result[0] = first[0];
        result[1] = last[1];

        return result;
    }
};