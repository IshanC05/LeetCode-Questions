class Solution {
public:
    int numberOfWays(string corridor) {
        
        vector<int>seats;
        
        int M = 1e9+7;
        
        for(int i = 0; i < corridor.size(); i++)
            if(corridor[i] == 'S')  seats.push_back(i);
        
        if(seats.size() % 2 != 0)   return 0;
        
        if(seats.size() == 2)   return 1;
        
        long long res = 0;
        
        int n = seats.size();
        
        for(int i = 1; i < n; i+=2){
            
            if(i + 1 < n){
                
                int len = seats[i + 1] - seats[i];
                
                if(res == 0)    res = len;
                
                else    res = (res * len) % M;              
                
            }
        }
        
        return res;
        
    }
};