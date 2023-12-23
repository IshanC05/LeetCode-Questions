class Solution {
public:
    bool isPathCrossing(string path) {
        int cx = 0, cy = 0;
        
        unordered_set<string>seen;
        seen.insert("0,0");
        
        for(char dir : path){
            
            if(dir == 'N')  ++cy;
            
            else if(dir == 'S')     --cy;
            
            else if(dir == 'E')     ++cx;
            
            else    --cx;
            
            string res = to_string(cx) + "," + to_string(cy);
            
            if(seen.find(res) != seen.end())   return true;
            
            seen.insert(res);
            
        }
        
        return false;
        
    }
};