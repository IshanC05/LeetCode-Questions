class Solution {
    public int maxFrequencyElements(int[] nums) {
        int[] freq = new int[101];
        
        for(int i : nums)
            ++freq[i];
        
        int maxF = 0;
        
        for(int i : freq)
            maxF = Math.max(maxF, i);
        
        int res = 0;
        
        for(int i : freq){
            if(i == maxF)   res += maxF;
        }
        
        return res;
    }
}