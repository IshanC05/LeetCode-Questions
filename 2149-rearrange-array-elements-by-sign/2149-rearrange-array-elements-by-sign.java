class Solution {
    public int[] rearrangeArray(int[] nums) {
        int n = nums.length;
        int[] res = new int[n];
        
        int i = 0, j = 0, k = 0;
        
        while(k < n){
            while(i < n && nums[i] < 0) ++i;
            if(i < n && nums[i] >= 0)   res[k++] = nums[i++];
        
            while(j < n && nums[j] >= 0) ++j;
                if(j < n && nums[j] < 0)    res[k++] = nums[j++];
        }
        
        return res;
    }
}