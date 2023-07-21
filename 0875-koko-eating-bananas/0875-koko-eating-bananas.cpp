class Solution {
public:
    
    bool isValid(vector<int>&arr, int h, int speed){
        
        long long curr = 0;
        
        for(int i = 0; i < arr.size(); i++){
            
            if(arr[i] <= speed) ++curr;
            
            else{
                
                curr += (arr[i] / speed);
                
                if(arr[i] % speed != 0)     ++curr;
                
            }
            
        }
        
        
        return curr <= h;
        
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        sort(piles.begin(), piles.end());
        
        int n = piles.size(), l = 1, r = piles[0];
        
        for(int i : piles)  r = max(h, i);
        
        int candidate = r;
        
        while(l <= r){
            
            int mid = l + (r - l) / 2;
            
            if(isValid(piles, h, mid)){
                
                candidate = mid;
                
                r = mid - 1;
                
            }
            
            else    l = mid + 1;
            
        }
        
        return candidate;
        
    }
};