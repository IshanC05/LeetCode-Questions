class Solution {
public:
    int helper(int n){
       int res = 0;
        
        while(n){
            if(n & 1)   ++res;
            n = (n >> 1);
        }
        
        return res;      
    }
    
    static bool cmp(pair<int,int>&a, pair<int,int>&b){
        
        if(a.second != b.second)    return a.second < b.second;
        
        return a.first < b.first;
        
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>>v;
        
        for(int i : arr){
            
            int count1s = helper(i);
            
            v.push_back({i, count1s});            
        }
        
        sort(v.begin(), v.end(), cmp);
        
        vector<int>ans;
        
        int k = 0;
        
        for(auto it : v){
            
            arr[k++] = it.first;
            
        }
        
        return arr;
    }
};