class Solution {
public:
    int totalMoney(int n) {
        
        int sum = 0, week = 0, start = 0;
        
        while(n--){
            
            ++start;
            
            sum += (week + start);
            
            if(start % 7 == 0){
                
                start = 0;
                
                ++week;
            }
        }
        
        return sum;
        
    }
};