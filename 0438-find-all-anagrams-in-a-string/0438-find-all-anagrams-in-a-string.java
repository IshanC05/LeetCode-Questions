class Solution {
    public boolean isEqual(int[] freqS, int[] freqP){
        for(int i = 0; i < 26; i++)     if(freqS[i] != freqP[i])    return false;
        return true;
    }
    public List<Integer> findAnagrams(String s, String p) {
        int k = p.length();
        
        int[] freqS = new int[26];
        int[] freqP = new int[26];
        
        for(char i : p.toCharArray())
            ++freqP[i - 'a'];
        
        List<Integer>res = new ArrayList<>();
        
        int i = 0, j = 0;
        
        while(j < s.length()){
            
            ++freqS[s.charAt(j) - 'a'];
            
            while(j - i + 1 > k){
                --freqS[s.charAt(i++) - 'a'];
            }
            
            if(j - i + 1 == k && isEqual(freqS, freqP))     res.add(i);
            
            ++j;
        }
        
        return res;
    }
}