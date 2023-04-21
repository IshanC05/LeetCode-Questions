class Solution {
public:
    void rotateArrayHelper(vector<int>&arr, int st, int en){
        while(st < en){
            swap(arr[st], arr[en]);
            ++st;
            --en;
        }
        return;
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if(k == n){
            return;
        }
        rotateArrayHelper(nums, 0, n-1);
        rotateArrayHelper(nums, 0, k-1);
        rotateArrayHelper(nums, k, n-1);
    }
};