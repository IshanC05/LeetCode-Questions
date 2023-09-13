class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n = ratings.size(), i = 1;
        
        int ans = n;
        
        while(i < n){
            
            if(ratings[i] == ratings[i - 1]){
                ++i;
                continue;
            }
            
            int peak = 0;
            
            while(ratings[i] > ratings[i - 1]){
                ++peak;
                ans += peak;
                ++i;
                if(i == n)  return ans;              
            }
            
            int dip = 0;
            
            while(i < n && ratings[i] < ratings[i - 1]){
                ++dip;
                ans += dip;
                ++i;                
            }
            
            ans -= min(peak, dip);
            
        }
        
        return ans;
        
    }
};