//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long merge(long long arr[], long long l, long long mid, long long h) {
        vector<long long> temp;
        long long i = l, j = mid + 1, count = 0;
    
        while (i <= mid && j <= h) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            } else {
                temp.push_back(arr[j++]);
                count += (mid - i + 1);
            }
        }
    
        while (i <= mid) {
            temp.push_back(arr[i++]);
        }
    
        while (j <= h) {
            temp.push_back(arr[j++]);
        }
    
        for (int k = 0; k < temp.size(); k++) {
            arr[l + k] = temp[k];
        }
    
        return count;
    }
    
    long long mergeSort(long long arr[], long long l, long long h) {
        long long count = 0;
    
        if (l < h) {
            long long mid = l + (h - l) / 2;
            count += mergeSort(arr, l, mid);
            count += mergeSort(arr, mid + 1, h);
            count += merge(arr, l, mid, h);
        }
    
        return count;
    }
    
    long long inversionCount(long long arr[], long long N) {
        return mergeSort(arr, 0, N - 1);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends