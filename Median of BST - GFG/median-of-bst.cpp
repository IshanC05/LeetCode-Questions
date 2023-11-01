//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



float findMedian(struct Node* node);

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));
 
   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

int main() {
  
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   //cout << t << endl;
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root = buildTree(s);

      // getline(cin, s);
       
        cout << findMedian(root) << endl;

      // cout<<"~"<<endl;
   }
   return 0;
}
// } Driver Code Ends


/*
Structure of the binary Search Tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// your task is to complete the Function
// Function should return median of the BST
void countNodes(Node* root, int &n){
    
    if(!root)   return;
    
    ++n;
    
    countNodes(root->left, n);
    
    countNodes(root->right, n);
    
}

void getKthNode(Node* root, int &k, int& ans){
    
    if(!root || k < 0 || ans != -1)     return;
    
    getKthNode(root->left, k, ans);
    
    --k;
    
    if(k == 0){
        ans = root->data;
        return;
    }
    
    getKthNode(root->right, k, ans);
    
}
float findMedian(struct Node *root)
{
      //Code here
    int n = 0;
    
    countNodes(root, n);
    
    if(n % 2 != 0){
        
        int ans = -1, k = (n + 1) / 2;
        
        getKthNode(root, k, ans);
        
        return ans;
      
    }
    
    int ans1 = -1, ans2 = -1, k1 = n / 2, k2 = k1 + 1;
    
    getKthNode(root, k1, ans1);
    
    getKthNode(root, k2, ans2);
    
    return ((ans1 + ans2) / 2.0);
}

