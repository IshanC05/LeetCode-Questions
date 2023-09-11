class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {      
        
        int maxSize = 0, n = groupSizes.size();
        
        for(int i = 0; i < n; i++){
            maxSize = max(maxSize, groupSizes[i]);
        }
        
        vector<vector<int>>ans;        
               
        for(int i = 1; i <= maxSize; i++){
            vector<int>temp;
            for(int j = 0; j < n; j++){
                if(groupSizes[j] == i){
                    groupSizes[j] = 0;
                    if(temp.size() < i) temp.push_back(j);
                    else{
                        ans.push_back(temp);
                        temp.clear();
                        temp.push_back(j);
                    }
                }
            }
            
            if(temp.size() == i)    ans.push_back(temp);
            
        }
        
        return ans;
        
    }
};