//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerRight(vector<int>arr){
        stack<int>st;
        vector<int>ans(arr.size(), -1);
        st.push(0);
        int i = 1;
        while(i < arr.size()){
            while(!st.empty() and arr[st.top()] > arr[i]){
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
            ++i;
        }
        return ans;
    }
    vector<int> nearestSmallerLeft(vector<int>arr){
        stack<int>st;
        int n = arr.size();
        vector<int>ans(n, -1);
        st.push(n - 1);
        int i = n - 2;
        while(i >= 0){
            while(!st.empty() and arr[st.top()] > arr[i]){
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
            i--;
        }
        return ans;
    }
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        // code here
        int n = arr.size();
        vector<int>left = nearestSmallerLeft(arr);
        vector<int>right = nearestSmallerRight(arr);
        vector<int>ans(n);
        for(int i = 0; i < n; i++){
            if(left[i] != -1 and right[i] != -1){
                int d1 = abs(left[i] - i);
                int d2 = abs(right[i] - i);
                if(d1 > d2){
                    ans[i] = right[i];
                }else if(d2 > d1){
                    ans[i] = left[i];
                }else{
                    int thLeft = arr[left[i]], thRight = arr[right[i]];
                    if(thLeft > thRight){
                        ans[i] = right[i];
                    }else if(thLeft < thRight){
                        ans[i] = left[i];
                    }else{
                        ans[i] = min(left[i], right[i]);
                    }
                }
            }else{
                ans[i] = max(left[i], right[i]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends