class Solution {
    public int[] findErrorNums(int[] nums) {
        int n = nums.length;
        
        int []count = new int[n + 1];
        
        for(int i : nums)
            ++count[i];
        
        int missing = -1, repeat = -1;
        
        for(int i = 1; i < n + 1; i++){
            if(count[i] == 2)   repeat = i;
            if(count[i] == 0)   missing = i; 
        }
        
        return new int[]{repeat, missing};
    }
}