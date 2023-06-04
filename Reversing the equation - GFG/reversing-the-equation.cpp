//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    bool isSpecial(char a){
        if(a == '+' || a == '-' || a == '*' || a == '/'){
            return true;
        }
        return false;
    }
    string reverseEqn (string s)
        {
            //code here.
            vector<string>nums;
            stack<char>st;
            int i = 0, n = s.size();
            string t = "";
            while(i < n){
                while(i < n and !isSpecial(s[i])){
                    t.push_back(s[i]);
                    ++i;
                }
                if(!t.empty()){
                    nums.push_back(t);
                    t = "";
                }
                st.push(s[i]);
                ++i;
            }
            nums.push_back(t);
            string ans = "";
            i = nums.size() - 1;
            while(i >= 0 and !st.empty()){
                ans = ans + nums[i--];
                ans.push_back(st.top());
                st.pop();
            }
            if(i == 0){
                ans = ans + nums[i--];
            }
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends