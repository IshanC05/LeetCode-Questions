class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        
        vector<pair<int,int>>arr;
        
        for(int i = 0; i < ranges.size(); i++){
            
            arr.push_back({i - ranges[i], i + ranges[i]});
            
        }
        
        int min = 0, max = 0, total = 0;
        
        while(max < n){
            
            for(int i = 0; i < ranges.size(); i++){
                
                int l = arr[i].first, r = arr[i].second;
                
                if(l <= min && r > max){
                    
                    max = r;
                    
                }
                
            }
            
            if(min == max)  return -1;
            
            min = max;
            
            ++total;
            
        }
        
        return total;
        
    }
};