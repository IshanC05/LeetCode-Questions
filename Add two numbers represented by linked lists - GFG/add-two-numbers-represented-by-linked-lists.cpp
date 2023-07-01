//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    Node* reverseLL(Node* head){
        
        if(!head || !head->next)    return head;
        
        Node* smallAns = reverseLL(head->next);
        Node* prevNode = head->next;
        prevNode->next = head;
        head->next = nullptr;
        
        return smallAns;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first = reverseLL(first);
        second = reverseLL(second);
        
        Node* head = nullptr, *tail = nullptr;
        
        int carry = 0;
        
        while(first || second || carry){
            
            int sum = 0;
            
            if(first){
                sum += first->data;
                first = first->next;
            }
            
            if(second){
                sum += second->data;
                second = second->next;
            }
            
            sum += carry;
            carry = sum / 10;
            sum = sum % 10;
            
            Node* temp = new Node(sum);
            
            if(head == nullptr){
                head = temp;
                tail = temp;
            }else{
                tail->next = temp;
                tail = temp;
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
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends