class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {        
        vector<int>freq(201, 0);
        
        for(int i : nums)   
            ++freq[i];
        
        vector<vector<int>>res;
        
        while(true){
            vector<int>temp;            
            
            for(int i = 1; i <= 200; i++){
                if(freq[i] != 0){
                    temp.push_back(i);
                    --freq[i];
                }
            }
            
            if(temp.size() == 0)    break;
            
            res.push_back(temp);            
        }
        
        return res;
    }
};