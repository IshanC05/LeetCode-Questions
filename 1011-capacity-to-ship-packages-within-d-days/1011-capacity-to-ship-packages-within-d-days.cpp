class Solution {
public:
    bool check(vector<int>& weights, int maxCapacity, int days){
        
        int reqDays = 1, weightSum = 0;
        
        for(int i = 0; i < weights.size(); i++){
            
            if(maxCapacity < weights[i])    return false;
            
            if(weightSum + weights[i] <= maxCapacity){
                weightSum += weights[i];
            }else{
                weightSum = weights[i];
                ++reqDays;
            }
            
            if(reqDays > days)  return false;            
        }
        
        return reqDays <= days;        
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        
        // sort(weights.begin(), weights.end());
        
        int l = 1, h = 1e8, ans = h;
        
        while(l <= h){
            
            int mid = l + (h - l) / 2;
            
            if(check(weights, mid, days) == true){
                ans = min(ans, mid);
                h = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        
        return ans;        
    }
};