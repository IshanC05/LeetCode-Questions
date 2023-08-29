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

class Solution
{
    public:
    
    Node* reverseLL(Node* head){
        
        if(!head || !head->next)    return head;
        
        Node* curNode = head;
        
        Node* smallAnsHead = reverseLL(head->next);
        
        Node* newTail = curNode->next;
        
        newTail->next = curNode;
        
        curNode->next = nullptr;
        
        return smallAnsHead;
    }
    
    Node *compute(Node *head)
    {
        // your code goes here
        
        if(!head || !head->next)    return head;
        
        head = reverseLL(head);
        
        Node* slow = head, *fast = head->next;
        
        while(fast){
            
            if(slow->data <= fast->data){
                
                slow->next = fast;
                
                slow = fast;
                
            }
            
            fast = fast->next;
            
        }
        
        slow->next = nullptr;
        
        head = reverseLL(head);
        
        return head;
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