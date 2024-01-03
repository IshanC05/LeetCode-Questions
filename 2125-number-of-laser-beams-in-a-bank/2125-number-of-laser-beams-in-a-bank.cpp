class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m = bank.size(), n = bank[0].size();
        
        vector<int>rowLaserCount(m, 0);
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                
                if(bank[i][j] == '1')   ++rowLaserCount[i];
                
            }
        }
        
        int res = 0, prev = 0, curr = 0;
        
        while(prev < m && rowLaserCount[prev] == 0)     
            ++prev;
        
        curr = prev + 1;
        
        while(curr < m){
            while(curr < m && rowLaserCount[curr] == 0)     
                ++curr;
            
            if(curr >= m)   break;
            
            res += (rowLaserCount[prev] * rowLaserCount[curr]);
            
            prev = curr;
            
            ++curr;
        }
        
        return res;
    }
};