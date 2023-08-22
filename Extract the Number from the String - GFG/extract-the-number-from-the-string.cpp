//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    long long ExtractNumber(string S){
        
        //code here
        
        long long num = 0;
        
        int n = S.size(), i = 0, count9 = 0;
        
        while(i < n){
            
            long long curr = 0;
    
            while(i < n && S[i] >= '0' && S[i] <= '9'){
                
                if(S[i] == '9') count9 = 1;            
                
                if(count9)  curr = 0;
                
                else    curr = curr * 10 + (S[i] - '0');
                
                ++i;
            }
            
            num = max(num, curr);
            
            if(i == n)  break;
            
            count9 = 0;
            
            ++i;
            
        }
        
        return num == 0 ? -1 : num;
        
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	string tc;
   	getline(cin, tc);
   	t = stoi(tc);
   	while(t--)
   	{
   		string s;
   		getline(cin, s);

   	
        Solution ob;
   		cout << ob.ExtractNumber(s) << "\n";
   	}

    return 0;
}

// } Driver Code Ends