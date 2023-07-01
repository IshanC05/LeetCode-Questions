//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    node* reverseLL(node* head){
        
        if(!head || !head->next)    return head;
        
        node* smallAns = reverseLL(head->next);
        node* prevNode = head->next;
        prevNode->next = head;
        head->next = nullptr;
        
        return smallAns;
    }
    struct node *reverse (struct node *head, int k)
    { 
        if(!head || k <= 1){
            return head;
        }
        node* length = head;
        int len = 0;
        while(length){
            ++len;
            length = length->next;
        }
        if(len <= k){
            return reverseLL(head);
        }
        node* tempHead = head;
        int i=1, tempK = k;
        while(i != tempK){
            ++i;
            tempHead = tempHead->next;
        }
        node* head2 = tempHead->next;
        tempHead->next = NULL;
        node* firstReversed = reverseLL(head);
        node* restLL = reverse(head2, k);
        tempHead = firstReversed;
        while(tempHead->next){
            tempHead = tempHead->next;
        }
        tempHead->next = restLL;
        return firstReversed;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends