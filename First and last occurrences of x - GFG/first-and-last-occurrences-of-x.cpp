//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    
    int first(int* arr, int l, int h, int x){
        
        int ans = h;
        
        while(l <= h){
            int mid = l + (h - l) / 2;
            if(arr[mid] == x){
                ans = mid;
                h = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        
        return ans;
    }
    
    int last(int* arr, int l, int h, int x){
        
        int ans = h;
        
        while(l <= h){
            int mid = l + (h - l) / 2;
            if(arr[mid] == x){
                ans = mid;
                l = mid + 1;
            }else{
                h = mid - 1;
            }
        }
        
        return ans;
    }
    
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        bool isPresent = false;
        int l = 0, h = n - 1, idx = -1;;
        
        while(l <= h){
            int mid = l + (h - l) / 2;
            if(arr[mid] == x){
                isPresent = true;
                idx = mid;
                break;
            }else if(arr[mid] < x){
                l = mid + 1;
            }else{
                h = mid - 1;
            }
        }
        
        if(!isPresent)  return {idx, idx};
        
        int idxF = first(arr, 0, idx, x);
        int idxL = last(arr, idx, n - 1, x);
        
        return {idxF, idxL};
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends