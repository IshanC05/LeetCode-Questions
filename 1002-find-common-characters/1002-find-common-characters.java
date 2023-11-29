class Solution {
    public List<String> commonChars(String[] words) {
        
        int main[] = new int[26];
        
        String s = words[0];
        
        for(int i = 0; i < s.length(); i++)
            ++main[s.charAt(i) - 'a'];
        
        for(int i = 1; i < words.length; ++i){
            
            s = words[i];
            
            int temp[] = new int[26];
            
            for(int j = 0; j < s.length(); j++)
                ++temp[s.charAt(j) - 'a'];
            
            for(int k = 0; k < 26; k++)
                main[k] = Math.min(main[k], temp[k]);
                          
        }
        
        List<String>res = new ArrayList<>();
        
        for(int i = 0; i < 26; i++){
            
            while(main[i] != 0){
                
                String ch = String.valueOf((char) (i + 'a'));
                
                res.add(ch);
                
                --main[i];
                
            }
            
        }
        
        return res;
        
    }
}