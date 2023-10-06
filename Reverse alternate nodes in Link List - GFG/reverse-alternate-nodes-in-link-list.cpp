//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    public:
    Node* rev(Node* head){
        
        if(!head || !head->next)    
            return head;
        
        Node* smallHead = rev(head->next);
        Node* tail = head->next;
        head->next = nullptr;
        tail->next = head;
        
        return smallHead;
    }
    
    void rearrange(struct Node *head)
    {
        //add code here
        if(!head || !head->next)    
            return;
        
        Node* head1 = nullptr, *tail1 = nullptr;
        Node* head2 = nullptr, *tail2 = nullptr;
        
        Node* temp = head;
        
        bool turn = true;
        
        while(temp){
            
            if(turn){
                
                if(!head1){
                    head1 = temp;
                    tail1 = temp;
                }else{
                    tail1->next = temp;
                    tail1 = temp;
                }
                
            }else{
                
                if(!head2){
                    head2 = temp;
                    tail2 = temp;
                }else{
                    tail2->next = temp;
                    tail2 = temp;
                }
            }
            
            turn = !turn;
            temp = temp->next;
        }
        
        tail2->next = nullptr;
        
        Node* reversedHead2 = rev(head2);
        
        tail1->next = reversedHead2;
        
        head = head1;
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends