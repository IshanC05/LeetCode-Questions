class Solution {
public:
    
    bool helper(vector<int>& arr, int target){
        
        unordered_set<int>visited;
        
        int i = 0, j = 1, n = arr.size();
        
        while(j < n){
            
            if(arr[j] - arr[i] <= target){}
            
            else{
                
                visited.insert(arr[j - 1]);
                
                i = j - 1;
                
            }
            
            ++j;
            
        }
        
        if(arr[n - 1] - arr[i] > target)    return false;
        
        i = n - 1, j = n - 2;
        
        while(j >= 0){
            
            if(arr[i] - arr[j] <= target && visited.count(arr[j]) == false){
                
                i = j;
                
            }
            
            --j;
            
        }
        
        if(arr[i] - arr[0] > target)    return false;
        
        return true;
        
    }
    
    int maxJump(vector<int>& stones) {
        
        int n = stones.size(), l = 1, h = stones[n - 1], ans = h;
        
        while(l <= h){
            
            int mid = l + (h - l) / 2;
            
            if(helper(stones, mid)){
                
                ans = mid;
                
                h = mid - 1;
                
            }
            
            else    l = mid + 1;
            
        }
        
        return ans;
        
    }
};