class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int x1 = -1, x2 = -1, countX1 = 0, countX2 = 0, n = nums.size();
        
        for(int i : nums){
            
            if(i == x1)     ++countX1;
            
            else if(i == x2)    ++countX2;
            
            else if(countX1 == 0)   x1 = i, countX1 = 1;
            
            else if(countX2 == 0)   x2 = i, countX2 = 1;
            
            else    --countX1, --countX2;
            
        }
        
        countX1 = 0, countX2 = 0;
        
        for(int i : nums){
            
            if(i == x1)     ++countX1;
            
            else if(i == x2)    ++countX2;
            
        }
        
        vector<int>ans;
        
        if(countX1 > n / 3) ans.push_back(x1);
        
        if(countX2 > n / 3) ans.push_back(x2);
        
        
        return ans;
    }
};