//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int kadane(int *arr, int n)
    {
        int curAns = arr[0], res = arr[0];
        for (int i = 1; i < n; i++)
        {
            curAns = max(arr[i], curAns + arr[i]);
            res = max(res, curAns);
        }
        return res;
    }
    int circularSubarraySum(int arr[], int n){
        
        // your code here
        int maxSubarraySum = kadane(arr, n);
        // if all numbers in array < 0 -> return maximum subarray
        if (maxSubarraySum < 0)
        {
            return maxSubarraySum;
        }
        int totalarraySum = 0;
        for (int i = 0; i < n; i++)
        {
            totalarraySum = totalarraySum + arr[i];
            arr[i] = arr[i] * (-1);
        }
        int minSubarraySum = kadane(arr, n) * (-1);
        int circularSubarraySum = totalarraySum - minSubarraySum;
        return max(maxSubarraySum, circularSubarraySum);
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends