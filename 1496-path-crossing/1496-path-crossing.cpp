class Solution {
public:
    bool isPathCrossing(string path) {
        int cx = 0, cy = 0;
        
        set<pair<int, int>>seen;
        seen.insert({cx, cy});
        
        for(char dir : path){
            
            if(dir == 'N')  ++cy;
            
            else if(dir == 'S')     --cy;
            
            else if(dir == 'E')     ++cx;
            
            else    --cx;
            
            if(seen.find({cx, cy}) != seen.end())   return true;
            
            seen.insert({cx, cy});
            
        }
        
        return false;
        
    }
};