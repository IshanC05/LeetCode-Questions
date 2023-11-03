class Solution {
public:
    bool isEqual(unordered_set<int>&a, unordered_set<int>&b){
        
        if(a.size() != b.size())    return false;
        
        for(auto it : a){
            
            if(b.find(it) == b.end())  return false;
            
        }
        
        return true;
        
    }
    vector<string> buildArray(vector<int>& target, int n) {
        
        int sz = target.size(), k = 0;
        
        stack<int>st;
        
        unordered_set<int>needed, present;
        
        for(auto i : target){
            needed.insert(i);
        }
        
        vector<string> ans;
        
        for(int i = 1; i <= n; i++){
            
            if(isEqual(needed, present))    break;
            
            if(needed.find(i) != needed.end()){
                
                st.push(i);
                
                present.insert(i);
                
                ans.push_back("Push");
                
            }else{
                
                ans.push_back("Push");
                
                ans.push_back("Pop");
                
            }
            
        }
        
        return ans;        
    }
};