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
    vector<int> nextGreater(int* nums, int n)
        {
            // int n = nums.size();
            stack<int> s;
            vector<int> res(n);

            for (int i = n - 1; i >= 0; i--)
            {
                while (!s.empty() and nums[s.top()] <= nums[i])
                {
                    s.pop();
                }
                if (s.empty())
                    res[i] = n;
                else
                    res[i] = s.top();

                s.push(i);
            }
            return res;
        }
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        vector<int> ans;
        vector<int> temp = nextGreater(arr, n);
        // int n = nums.size();

        int j = 0;

        for (int i = 0; i <= n - k; i++)
        {
            if (j < i)
            {
                j = i;
            }
            while (temp[j] < i + k)
            {
                j = temp[j];
            }

            ans.push_back(arr[j]);
        }

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