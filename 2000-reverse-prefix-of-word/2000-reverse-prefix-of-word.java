class Solution {
    public String rev(StringBuilder word, int r){
        int l = 0;
        
        while(l < r){
            char curr = word.charAt(l);
            word.setCharAt(l, word.charAt(r));
            word.setCharAt(r, curr);
            ++l;
            --r;
        }
        
        return word.toString();
    }
    
    public String reversePrefix(String word, char ch) {
        StringBuilder temp = new StringBuilder(word);
        
        for(int i = 0; i < temp.length(); i++){
            if(word.charAt(i) == ch)    
                return rev(temp, i);
        }
        
        return word;            
    }
}