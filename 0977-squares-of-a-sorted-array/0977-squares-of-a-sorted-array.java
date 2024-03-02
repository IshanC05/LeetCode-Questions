class Solution {
    public int[] sortedSquares(int[] nums) {
        int n = nums.length;
        
        for(int i = 0; i < n; i++){
            nums[i] = (nums[i] * nums[i]);
        }
        
        int res[] = new int[n];
        int i = 0, j = n - 1, k = n - 1;
        
        while(i <= j){
            if(nums[i] >= nums[j]){
                res[k--] = nums[i++];
            }else{
                res[k--] = nums[j--];
            }
        }
        
        return res;
    }
}