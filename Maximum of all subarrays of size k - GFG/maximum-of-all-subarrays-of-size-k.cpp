//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int *arr, int n, int k) {
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

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends