class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        
        int P = 0, G = 0, M = 0;
        
        int res = 0, gsz = garbage.size();
        
        for(int i = 0; i < gsz; i++){
            
            for(char j : garbage[i]){
                
                if(j == 'P')    P = i;
                
                else if(j == 'G')   G = i;
                
                else    M = i;
                
                ++res;
                
            }
            
        }
        
        for(int i = 1; i < travel.size(); i++){         
            
            travel[i] = travel[i] + travel[i - 1];
            
        }
        
        res += P - 1 >= 0 ? travel[P - 1] : 0;
        
        res += M - 1 >= 0 ? travel[M - 1] : 0;
        
        res += G - 1 >= 0 ? travel[G - 1] : 0;
           
        return res;
    }
};