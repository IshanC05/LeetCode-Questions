class Solution {
    public List<List<Integer>> findMatrix(int[] nums) {
        int freq[] = new int[201];
        
        for(int i : nums)
            ++freq[i];
        
        List<List<Integer>> res = new ArrayList<>();
        
        while(true){
            List<Integer> temp = new ArrayList<>();
            
            for(int i = 1; i < 201; i++){
                if(freq[i] != 0){
                    temp.add(i);
                    --freq[i];
                }
            }
            
            if(temp.isEmpty())  break;
            
            res.add(temp);
        }
        
        return res;
    }
}