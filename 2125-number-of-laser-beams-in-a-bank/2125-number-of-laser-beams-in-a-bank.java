class Solution {
    public int numberOfBeams(String[] bank) {
        int res = 0, prev = 0;
        
        for(int i = 0; i < bank.length; i++){
            
            int curr = 0;
            
            for(int j = 0; j < bank[i].length(); j++){
                if(bank[i].charAt(j) == '1')    ++curr;
            }
            
            if(curr != 0){
                res += (prev * curr);
                prev = curr;
            }
        }
        
        return res;
    }
}