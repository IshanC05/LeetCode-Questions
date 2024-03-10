class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        boolean[] isPresent = new boolean[1001];
        
        for(int i : nums1)  
            isPresent[i] = true;
        
        List<Integer> resList = new ArrayList<>();
        
        for(int j : nums2){
            if(isPresent[j]){
                resList.add(j);
                isPresent[j] = false;
            }
        }
        
        return resList.stream().mapToInt(Integer::intValue).toArray();
    }
}