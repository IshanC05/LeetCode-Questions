//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


// } Driver Code Ends
// you are required to complete this function 
// function should print the required range
typedef pair<int,pair<int,int>> triplet;

class compare {
    public:
    bool operator()(triplet a, triplet b)
    {
        return a.first > b.first;
    }
};

class Solution{
    public:
    
    pair<int,int> findSmallestRange(int arr[][N], int n, int k)
    {
          //code here
          
        int minE = INT_MAX, maxE = INT_MIN;
        
        priority_queue<triplet, vector<triplet>, compare >pq;
        
        for(int i = 0; i < k; i++){
            
            minE = min(minE, arr[i][0]);
            
            maxE = max(maxE, arr[i][0]);
            
            pq.push({arr[i][0], {i, 0}});
            
        }
        
        int start = minE, end = maxE;
        
        while(!pq.empty()){
            
            triplet t = pq.top();
            pq.pop();
            
            minE = t.first;
            
            if(maxE - minE < end - start){
                
                start = minE;
                
                end = maxE;
                
            }
            
            if(t.second.second + 1 < n){
                
                maxE = max(maxE, arr[t.second.first][t.second.second + 1]);
                
                pq.push({arr[t.second.first][t.second.second + 1], {t.second.first, t.second.second + 1}});
                
            }else{
                break;
            }
            
        }
        
        return {start, end};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}


// } Driver Code Ends