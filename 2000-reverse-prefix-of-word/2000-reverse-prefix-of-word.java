class Solution {
    public String reversePrefix(String word, char ch) {
        StringBuilder temp = new StringBuilder(word);
        
        for(int i = 0; i < temp.length(); i++){
            if(word.charAt(i) == ch){
                StringBuilder left = new StringBuilder(temp.substring(0, i + 1));
                StringBuilder right = new StringBuilder(temp.substring(i + 1));
                left.reverse();
                left.append(right);
                return left.toString();
            }
        }
        
        return word;            
    }
}