//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int firstIdx(int* nums, int n, int target){
        int l = 0, h = n - 1, ans = -1;
        while(l <= h){
            int mid = l + (h-l)/2;
            if(nums[mid] < target){
                l = mid + 1;
            }else if(nums[mid] > target){
                h = mid - 1;
            }else{
                if(mid == 0 || nums[mid] != nums[mid -1]){
                    return mid;
                }else{
                    h = mid - 1;
                }
            }
        }
        return ans;
    }
    int lastIdx(int* nums, int n, int target){
        int l = 0, h = n - 1, ans = -1;
        while(l <= h){
            int mid = l + (h - l) / 2;
            if(nums[mid] > target){
                h = mid - 1;
            }else if(nums[mid] < target){
                l = mid + 1;
            }else{
                if(mid == n - 1 || nums[mid] != nums[mid + 1]){
                    return mid;
                }else{
                    l = mid + 1;
                }
            }
        }
        return ans;
    }
	int count(int arr[], int n, int x) {
	    // code here
	    int f = firstIdx(arr, n, x);
	    if(f == -1){
	        return 0;
	    }
	    return (lastIdx(arr, n, x) - f + 1);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends