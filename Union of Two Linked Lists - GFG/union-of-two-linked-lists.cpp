//{ Driver Code Starts
#include<bits/stdc++.h>
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


// } Driver Code Ends
/*
// structure of the node is as follows

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
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        // code here
        priority_queue<int, vector<int>, greater<int>>pq;
        
        while(head1){
            pq.push(head1->data);
            head1 = head1->next;
        }
        
        while(head2){
            pq.push(head2->data);
            head2 = head2->next;
        }
        
        Node* head = nullptr, *tail = nullptr;
        
        while(!pq.empty()){
            int x = pq.top();
            pq.pop();
            Node* newNode = new Node(x);
            if(tail == nullptr){
                head = newNode;
                tail = newNode;
            }else{
                if(tail->data != newNode->data){
                    tail->next = newNode;
                    tail = newNode;    
                }
            }
        }
        
        return head;
    }
};


//{ Driver Code Starts.

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
        Solution obj;
        Node* head = obj.makeUnion(first,second);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends