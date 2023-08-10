class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        
        for(int i = 0; i < arr.size(); i++){
            
            pq.push({abs(x - arr[i]), arr[i]});
            
        }
        
        int i = 0;
        
        vector<int>ans(k);
        
        while(k--){
            
            ans[i++] = pq.top().second;
            
            pq.pop();
            
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};