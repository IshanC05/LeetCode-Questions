class Solution {
public:
    vector<vector<int>> generate(int numRows) {
     
        vector<vector<int>>ans;
        
        ans.push_back({1});
        
        if(numRows == 1)  return ans;
        
        ans.push_back({1,1});
        
        if(numRows == 2)  return ans;
        
        for(int i = 3; i <= numRows; i++){
            
            vector<int>temp(i, 1);
            
            int k = 0;
            
            for(int j = 1; j < i - 1; j++){
                
                temp[j] =  ans[i - 2][k] + ans[i - 2][k + 1];
                
                ++k;
                
            }
            
            ans.push_back(temp);
            
        }
        
        return ans;
        
    }
};