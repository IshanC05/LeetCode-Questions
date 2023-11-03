class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        
        int i = 1;
        
        vector<string>ans;
        
        for(int num : target){
            
            while(i < num){
                
                ans.push_back("Push");
                
                ans.push_back("Pop");
                
                ++i;
            }
            
            ans.push_back("Push");
                  
            ++i;   
        }
        
        return ans;
        
    }
};