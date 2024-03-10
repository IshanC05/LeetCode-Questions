class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        boolean[] arr = new boolean[1001];
        boolean[] brr = new boolean[1001];
        
        for(int i : nums1)  arr[i] = true;
        for(int j : nums2)  brr[j] = true;
        
        List<Integer> resList = new ArrayList<>();
        
        for(int i = 0; i < 1001; i++){
            if(arr[i] && (arr[i] == brr[i]))    resList.add(i);
        }
        
        return resList.stream().mapToInt(Integer::intValue).toArray();
    }
}