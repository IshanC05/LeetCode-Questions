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
        cout << node->data%10; 
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

class Solution
{
    public:
    Node* reverseLL(Node* head){
        
        if(!head || !head->next)    return head;
        
        Node* smallHead = reverseLL(head->next);
        Node* nextNode = head->next;
        nextNode->next = head;
        head->next = nullptr;
        
        return smallHead;
    }
    Node* addOne(Node *head) 
    {
        head = reverseLL(head);
        
        Node* temp = head;
        temp->data = temp->data + 1;
        int carry = temp->data / 10;
        temp->data = temp->data % 10;
        temp = temp->next;
        
        while(temp || carry){
            if(temp){
                temp->data += carry;
                carry = temp->data / 10;
                temp->data = temp->data % 10;
                temp = temp->next;
            }else if(temp == nullptr and carry != 0){
                Node* newHead = new Node(carry);
                carry = 0;
                head = reverseLL(head);
                newHead->next = head;
                head = newHead;
                return head;
            }
        }
        
        return reverseLL(head);
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends