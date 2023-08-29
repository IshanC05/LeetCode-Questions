class Solution {
public:
    int bestClosingTime(string customers) {
        
        int minPenalty = INT_MAX, countY = 0, countN = 0;
        
        int n = customers.size(), minHour = n;
        
        for(int i = 0; i < n; i++){
            
            if(customers[i] == 'Y')     ++countY;
            
        }
        
        for(int j = 0; j <= n; j++){
            
            int curPenalty = countY + countN;
            
            if(minPenalty > curPenalty){
                
                minPenalty = curPenalty;
                
                minHour = j;
                
            }
            
            if(j < n){
                
                if(customers[j] == 'Y')     --countY;
                
                else    ++countN;
                
            }
            
        }
        
        return minHour;
        
    }
};