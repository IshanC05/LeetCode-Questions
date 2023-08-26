class Solution {
public:
    
    int findLongestChain(vector<vector<int>>& pairs) {
        
        sort(pairs.begin(), pairs.end());
        
        int ans = 0, last = INT_MIN;
        
        for(int i = 0; i < pairs.size(); i++){
            
            if(last == INT_MIN || last < pairs[i][0]){
                
                last = pairs[i][1];
                
                ++ans;
                
            }else if(last > pairs[i][1]){
                
                last = pairs[i][1];
                
            }
            
        }
        
        return ans;
        
    }
};