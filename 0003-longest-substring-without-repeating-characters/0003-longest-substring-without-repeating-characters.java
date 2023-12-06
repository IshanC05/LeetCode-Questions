class Solution {
    public int lengthOfLongestSubstring(String s) {
        
        int i = 0, j = 0, n = s.length();
        
        int res = 0;
        
        Set<Character>st = new HashSet<>();
        
        while(j < n){
            
            while(i < j && st.contains(s.charAt(j))){
                
                st.remove(s.charAt(i));
                
                ++i;
                
            }
            
            st.add(s.charAt(j));
            
            res = Math.max(res, st.size());
            
            ++j;
            
        }
        
        return res;
        
    }
}