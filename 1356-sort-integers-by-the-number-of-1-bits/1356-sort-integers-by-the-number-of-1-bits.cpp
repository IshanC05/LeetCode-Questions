class Solution {
public:
    
    int get1s(int n){
        
        if(n == 0 || n == 1)  return n;
        
        int count = 0, mask = 1;
        
        while(n){
            
            count = (mask & n) ? ++count : count;
            
            n = (n >> 1);
            
        }
        
        return count;
        
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        
        vector<pair<int,int>>temp;
        
        for(int i : arr){
            
            int count = get1s(i);
            
            temp.push_back(make_pair(count, i));
            
        }
        
        sort(temp.begin(), temp.end());
        
        vector<int>ans;
        
        for(int i = 0; i < temp.size(); i++)    ans.push_back(temp[i].second);
        
        return ans;
        
    }
};