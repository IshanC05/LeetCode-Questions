class Solution {
    public int[] singleNumber(int[] nums) {
        Set<Integer> seen = new HashSet<>();
        
        for(int num : nums){
            if(seen.contains(num))  seen.remove(num);
            else    seen.add(num);
        }
        
        Integer[] tempArr = seen.toArray(new Integer[0]);
        
        int[] res = new int[tempArr.length];
        
        for(int i = 0; i < res.length; i++)
            res[i] = tempArr[i];
        
        return res;
    }
}