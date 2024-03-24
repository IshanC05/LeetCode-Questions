class Solution {
    public int findDuplicate(int[] nums) {
        boolean[] seen = new boolean[100005];
        
        for(int i : nums){
            if(seen[i])     return i;
            seen[i] = true;
        }
        
        return -1;
    }
}