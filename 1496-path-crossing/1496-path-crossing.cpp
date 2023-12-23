class Solution {
public:
    bool isPathCrossing(string path) {
        int x = 0, y = 0;
        
        unordered_set<string>seen;
        seen.insert("0,0");
        
        for(char dir : path){
            
            if(dir == 'N')  ++y;
            
            else if(dir == 'S')     --y;
            
            else if(dir == 'E')     ++x;
            
            else    --x;
            
            string res = to_string(x) + "," + to_string(y);
            
            if(seen.find(res) != seen.end())   return true;
            
            seen.insert(res);
            
        }
        
        return false;
        
    }
};