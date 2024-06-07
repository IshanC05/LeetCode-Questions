class Solution {
    private boolean isRoot(String word, String root){
        if(word.length() < root.length()) return false;
        
        for(int i = 0; i < root.length(); i++)
            if(root.charAt(i) != word.charAt(i)) return false;
        
        return true;
    }
    
    public String replaceWords(List<String> dictionary, String sentence) {
        String[] words = sentence.split(" ");
        String[] res = new String[words.length];
        
        for(int i = 0; i < words.length; i++){
            String word = words[i];
            
            for(String root : dictionary){
                if (isRoot(word, root)) {
                    if (res[i] == null || root.length() < res[i].length()) {
                        res[i] = root;
                    }
                }
            }
        }
        
        StringBuilder out = new StringBuilder();
        
        for(int i = 0; i < words.length; i++){
            if(res[i] == null) out.append(words[i]);
            else out.append(res[i]);
            
            if(i != words.length - 1) out.append(' ');
        }
        
        return out.toString();
    }
}