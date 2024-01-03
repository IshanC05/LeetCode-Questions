class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m = bank.size(), n = bank[0].size();
        int res = 0, prev = 0;
        
        for(int i = 0; i < m; i++){
            
            int count = 0;
            
            for(int j = 0; j < n; j++){
                if(bank[i][j] == '1')   ++count;
            }
         
            if(count != 0){
                res += (prev * count);
                prev = count;
            }
            
        }
        
        return res;
    }
};