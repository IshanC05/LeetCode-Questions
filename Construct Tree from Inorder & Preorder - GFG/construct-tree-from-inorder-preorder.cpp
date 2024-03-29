//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    Node* helper(int* in, int* pre, int inS, int inE, int preS, int preE){
        if(inS > inE){
            return NULL;
        }
        int rootData = pre[preS];
        int rootIdx = -1;
        for(int i = inS; i <= inE; i++){
            if(in[i] == rootData){
                rootIdx = i;
                break;
            }
        }
        int lInS = inS;
        int lInE = rootIdx - 1;
        int lPreS = preS + 1; 
        int lPreE = lInE - lInS + lPreS;
        int rPreS = lPreE + 1; 
        int rPreE = preE;
        int rInS = rootIdx + 1;
        int rInE = inE;
        
        Node* root = new Node(rootData);
        root->left = helper(in, pre, lInS, lInE, lPreS, lPreE);
        root->right = helper(in, pre, rInS, rInE, rPreS, rPreE);
        
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        return helper(in, pre, 0, n-1, 0, n-1);   
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends