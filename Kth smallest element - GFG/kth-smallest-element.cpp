//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    
    int partition(int arr[], int l, int r, int pivot){
        
        int i = l, j = l;
        
        while(i <= r){
            
            if(arr[i] <= pivot){
                
                swap(arr[i], arr[j++]);
                
            }
            
            ++i;
            
        }
        
        return j - 1;
        
    }
    
    int quickSelect(int arr[], int l, int r, int k){
        
        if(l > r)   return -1;
        
        int pivot = arr[r];
        
        int pivotIdx = partition(arr, l, r, pivot);
        
        if(pivotIdx == k)   return arr[pivotIdx];
        
        else if(pivotIdx > k)   return quickSelect(arr, l, pivotIdx - 1, k);
        
        return quickSelect(arr, pivotIdx + 1, r, k);
        
    }
    
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        return quickSelect(arr, l, r, k - 1);
        
    }
};

//{ Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends