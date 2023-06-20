//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{


	public:
	long int returnMaxSum(int A[], int B[], int n)
	{
	   // Your code goes here
	   long i = 0, j = 0, sum = 0, maxSum = 0;
	   unordered_set<int>charSet;
	   while(j < n){
	       if(!charSet.count(A[j])){
	            sum += B[j];
                charSet.insert(A[j++]);
            }else{
                sum -= B[i];
                charSet.erase(A[i++]);
            }
	        maxSum = max(maxSum, sum);
	   }
	   return maxSum;
	}

};
	  


//{ Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,i;
	    cin>>n;
	    int a[n],b[n];
	    for(i=0;i<n;i++)
	      cin>>a[i];
	     for(i=0;i<n;i++)
	     cin>>b[i];
        
        

        Solution ob;
		cout << ob.returnMaxSum(a, b, n);
        
	    cout << "\n";
	     
    }
    return 0;
}




// } Driver Code Ends