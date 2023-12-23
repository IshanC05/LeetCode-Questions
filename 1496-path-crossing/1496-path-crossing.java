class Solution {
    public boolean isPathCrossing(String path) {
        int x = 0, y = 0;
        
        Set<String> seen = new HashSet<>();
        seen.add("0,0");
        
        for(char dir : path.toCharArray()){
            
            if(dir == 'N')  ++y;
            
            else if(dir == 'S')     --y;
            
            else if(dir == 'E')     ++x;
            
            else    --x;
            
            String res = String.valueOf(x) + "," + String.valueOf(y);
            
            if(seen.contains(res))  return true;
            
            seen.add(res);
        }
        
        return false;
    }
}