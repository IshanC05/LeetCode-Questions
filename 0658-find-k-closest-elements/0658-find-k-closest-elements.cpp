class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int l = 0, h = arr.size() - 1;
        
        while(h - l >= k){
            
            if(abs(arr[l] - x) > abs(arr[h] - x)) ++l;
            
            else    --h;
            
        }
        
        vector<int>ans(arr.begin() + l, arr.begin() + l + k);
        
        return ans;
    }
};