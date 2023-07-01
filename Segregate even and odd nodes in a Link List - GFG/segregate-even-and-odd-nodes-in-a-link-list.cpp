//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        if(N == 1)  return head;
        
        Node* odd = nullptr, *oddT = nullptr, *even = nullptr, *evenT = nullptr;
        
        Node* temp = head;
        
        while(temp){
            if(temp->data % 2 == 0){
                if(even == nullptr){
                    even = temp;
                    evenT = temp;
                }else{
                    evenT->next = temp;
                    evenT = temp;
                }
            }else{
                if(odd == nullptr){
                    odd = temp;
                    oddT = temp;
                }else{
                    oddT->next = temp;
                    oddT = temp;
                }
            }
            temp = temp->next;
        }
        
        if(even != nullptr){
            head = even;
            evenT->next = odd;
        }else{
            head = odd;
        }
        
        if(oddT)    oddT->next = nullptr;
        
        return head;
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends