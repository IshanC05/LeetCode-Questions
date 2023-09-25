//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // code here
        
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        vector<int>ans;
        set<pair<int,int>>st;
        priority_queue<pair<int,pair<int,int>>>pq;
        
        pq.push({A[N - 1] + B[N - 1], {N - 1, N - 1}});
        st.insert({N - 1, N - 1});
        
        while(K--){
            
            auto p = pq.top();
            int sum = p.first;
            int i = p.second.first;
            int j = p.second.second;
            pq.pop();
            
            ans.push_back(sum);
            
            if(i - 1 >= 0 && st.find({i - 1, j}) == st.end()){
                pq.push({A[i - 1] + B[j], {i - 1, j}});
                st.insert({i - 1, j});
            }
            
            if(j - 1 >= 0 && st.find({i, j - 1}) == st.end()){
                pq.push({A[i] + B[j - 1], {i, j - 1}});
                st.insert({i, j - 1});
            }
            
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends