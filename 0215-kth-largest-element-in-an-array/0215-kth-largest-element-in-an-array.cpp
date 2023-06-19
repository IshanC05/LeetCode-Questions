class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        
        int n = nums.size(), ans = 0;
        
        for(int i = 0; i < n; i++){
            pq.push(nums[i]);
        }
        
        while(k--){
            ans = pq.top();
            pq.pop();
        }
        
        return ans;
    }
};