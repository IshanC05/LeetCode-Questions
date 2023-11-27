class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        
        int n = arr.size();
        
        vector<int> ans;
        deque<int> dq;
    
        for (int i = 0; i < k; i++) {
            // Remove elements from the back of the deque if they are smaller than the current element.
            while (!dq.empty() && arr[i] >= arr[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
    
        for (int i = k; i < n; i++) {
            // The front element of the deque contains the maximum for the previous subarray.
            ans.push_back(arr[dq.front()]);
    
            // Remove elements from the front of the deque if they are no longer in the current subarray.
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
    
            // Remove elements from the back of the deque if they are smaller than the current element.
            while (!dq.empty() && arr[i] >= arr[dq.back()]) {
                dq.pop_back();
            }
    
            dq.push_back(i);
        }
    
        // Add the maximum of the last subarray to the 'ans' vector.
        ans.push_back(arr[dq.front()]);
    
        return ans;
        
    }
};