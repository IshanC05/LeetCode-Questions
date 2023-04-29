class Solution
{
    public:
    TreeNode* helper(vector<int> in, vector<int> pre, int inS, int inE, int preS, int preE){
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
        
        TreeNode* root = new TreeNode(rootData);
        root->left = helper(in, pre, lInS, lInE, lPreS, lPreE);
        root->right = helper(in, pre, rInS, rInE, rPreS, rPreE);
        
        return root;
    }
    TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = inorder.size();
        return helper(inorder, preorder, 0, n-1, 0, n-1);
    }
};