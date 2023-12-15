class Solution {
    public String destCity(List<List<String>> paths) {
     
        Set<String>sources = new HashSet<>();
        
        for(List<String> path : paths){
            
            String u = path.get(0);
            sources.add(u);
        }
        
        for(List<String> path : paths){
            
            String v = path.get(1);
            if(!sources.contains(v))   return v;
        }
        
        return new String();
        
    }
}