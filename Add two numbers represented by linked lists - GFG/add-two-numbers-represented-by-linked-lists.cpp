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
    struct Node* addTwoLists(struct Node* l1, struct Node* l2)
    {
        // code here
        int carry = 0;
        Node* ans = NULL;
        Node* tail = NULL;
        l1 = reverseLL(l1); 
        l2 = reverseLL(l2);
        while(l1 || l2 || carry){
            int sum = 0;
            if(l1){
                sum = sum + l1->data;
                l1 = l1->next;
            }
            if(l2){
                sum = sum + l2->data;
                l2 = l2->next;
            }
            sum = sum + carry;
            carry = sum / 10;
            sum = sum % 10;
            Node* temp = new Node(sum);
            if(!tail){
                ans = temp;
                tail = temp;
            }else{
                tail->next = temp;
                tail = temp;
            }
        }
        return reverseLL(ans);
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