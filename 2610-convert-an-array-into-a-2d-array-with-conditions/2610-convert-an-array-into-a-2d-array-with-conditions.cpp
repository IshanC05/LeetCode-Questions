class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int>freq(201, 0);
        for(int i = 0; i < nums.size(); i++){
            ++freq[nums[i]];
        }
        vector<vector<int>>ans;
        bool hasElems = true;
        
        while(hasElems){
            hasElems = false;
            vector<int>temp;
            for(int i = 0; i < 201; i++){
                if(freq[i] != 0){
                    hasElems = true;
                    temp.push_back(i);
                    --freq[i];
                }
            }
            if(hasElems == true){
                ans.push_back(temp);    
            }
        }
        return ans;
    }
};