class Solution {
    public String reverseWords(String s) {
        List<String> words = new ArrayList<>();
        int n = s.length();
        
        StringBuilder sb = new StringBuilder();
        
        for(int i = 0; i < n;){
            
            sb.setLength(0);
            
            while(i < n && s.charAt(i) == ' ')
                ++i;
            
            while(i < n && s.charAt(i) != ' ')
                sb.append(s.charAt(i++));
            
            if(sb.length() != 0){
                words.add(sb.toString());
            }
        }
        
        sb.setLength(0);
        
        for(int i = words.size() - 1; i >= 0; i--){
            sb.append(words.get(i));
            
            if(i != 0)  sb.append(' ');
        }
        
        return sb.toString();
    }
}