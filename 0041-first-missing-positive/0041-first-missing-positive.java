class Solution {
    public int firstMissingPositive(int[] nums) {
        Set<Integer>set = Arrays.stream(nums).boxed().collect(Collectors.toSet());
        
        int start = 1;
        
        while(set.contains(start)){
            ++start;
        }
        
        return start;
    }
}