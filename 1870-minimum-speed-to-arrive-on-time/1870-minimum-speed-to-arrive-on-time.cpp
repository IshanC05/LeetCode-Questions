class Solution {
public:
    bool helper(vector<int>&arr, int speed, double hour){
        
        double currHours = 0.0;
        
        for(int i = 0; i < arr.size() - 1; i++){
            
            currHours += ceil(((double) arr[i]) / ((double) speed));            
        }
        
        currHours += arr[arr.size() - 1] / (double) speed;
        
        return currHours <= hour;
        
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        
        int l = 1, h = 1e7, ans = -1;
        
        while(l <= h){
            
            int mid = l + (h - l) / 2;
            
            if(helper(dist, mid, hour)){
                
                ans = mid;
                
                h = mid - 1;
                
            }
            
            else    l = mid + 1;
            
        }
        
        return ans;
        
    }

};