class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>>res = new ArrayList<>();
        Map<String, List<String>>mp = new HashMap<>();
        
        for(String s : strs){
            String t = s;
            
            char temp[] = s.toCharArray();
            Arrays.sort(temp);
            String key = new String(temp);
            
            List<String>currList = mp.getOrDefault(key, new ArrayList<String>());
            
            currList.add(t);
            
            mp.put(key, currList);
        }
        
        for(List<String>list : mp.values()){
            res.add(list);
        }
        
        return res;
    }
}