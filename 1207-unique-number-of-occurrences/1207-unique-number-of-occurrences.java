class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        int freq[] = new int[2005];
        
        for(int i : arr){
            if(i < 0)   i = (i * (-1)) + 1000;
            ++freq[i];   
        }
        
        Arrays.sort(freq);
        
        for(int i = 1; i < 2005; i++){
            if(freq[i - 1] == freq[i] && freq[i] != 0)  return false;
        }
        
        return true;
    }
}