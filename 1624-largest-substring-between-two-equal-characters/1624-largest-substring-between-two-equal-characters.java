class Solution {
    public int maxLengthBetweenEqualCharacters(String s) {
        int lastIdx[] = new int[26];
        int res = -1;
        
        for(int i = 0; i < 26; i++) 
            lastIdx[i] = -1;
        
        for(int i = 0; i < s.length(); i++){
            
            if(lastIdx[s.charAt(i) - 'a'] == -1)    lastIdx[s.charAt(i) - 'a'] = i;
            
            else    res = Math.max(res, i - lastIdx[s.charAt(i) - 'a'] - 1);
        }
        
        return res;
    }
}