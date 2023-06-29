//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node* reverseList(struct Node *head){
        // code here
        // return head of reversed list
        if(!head || !head->next)    return head;
        
        Node* smallAns = reverseList(head->next);
        Node* prevNode = head->next;
        prevNode->next = head;
        head->next = nullptr;
        
        return smallAns;
    }
    Node *compute(Node *head)
    {
        // your code goes here
        if(!head || !head->next)    return head;
        
        head = reverseList(head);
        
        Node* slow = head, *fast = head->next;
        
        while(fast){
            if(fast->data >= slow->data){
                slow->next = fast;
                slow = fast;
            }
            fast = fast->next;
        }
        
        slow->next = nullptr;
        
        return reverseList(head);
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends