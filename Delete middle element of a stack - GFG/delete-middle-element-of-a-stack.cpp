//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void deleteVal(stack<int>&s, int m, int size){
        
        if(s.empty())   return;
        
        int t = s.top();
        
        s.pop();
        
        deleteVal(s, m, size - 1);
        
        if(m == size)   return;
        
        s.push(t);
        
        return;
        
    }
    
    
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here.. 
        
        if(s.empty())   return;
        
        else if(sizeOfStack == 1){
            
            s.pop();
            
            return;
        }
        
        int mid = sizeOfStack % 2 == 0 ? sizeOfStack / 2 : (sizeOfStack + 1) / 2;
        
        deleteVal(s, mid, sizeOfStack);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends