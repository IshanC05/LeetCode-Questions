class Solution {
    boolean isVowel(char a){
        a = Character.toLowerCase(a);
        return (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u');
    }
    public boolean halvesAreAlike(String s) {
        int a = 0, b = 0, n = s.length();
        
        for(int i = 0; i < n; i++){
            if(isVowel(s.charAt(i))){
                
                if(i < n / 2)   ++a;
                
                else    ++b;
                
            }
        }
        
        return a == b;
    }
}