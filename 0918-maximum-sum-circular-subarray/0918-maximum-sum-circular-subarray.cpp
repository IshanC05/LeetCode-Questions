class Solution {
public:
    int kadane(vector<int>arr, int n)
    {
        int curAns = arr[0], res = arr[0];
        for (int i = 1; i < n; i++)
        {
            curAns = max(arr[i], curAns + arr[i]);
            res = max(res, curAns);
        }
        return res;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int maxSubarraySum = kadane(nums, n);
        // if all numbers in array < 0 -> return maximum subarray
        if (maxSubarraySum < 0)
        {
            return maxSubarraySum;
        }
        int totalarraySum = 0;
        for (int i = 0; i < n; i++)
        {
            totalarraySum = totalarraySum + nums[i];
            nums[i] = nums[i] * (-1);
        }
        int minSubarraySum = kadane(nums, n) * (-1);
        int circularSubarraySum = totalarraySum - minSubarraySum;
        return max(maxSubarraySum, circularSubarraySum);
    }
};