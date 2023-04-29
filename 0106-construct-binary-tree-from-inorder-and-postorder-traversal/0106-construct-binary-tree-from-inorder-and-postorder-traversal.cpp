class Solution {
public:
    TreeNode* helper(vector<int>in, vector<int>po, int inS, int inE, int poS, int poE){
        if(inS > inE){
            return NULL;
        }
        int rootData = po[poE];
        TreeNode* root = new TreeNode(rootData);
        
        int rootIdx = -1;
        for(int i = inS; i <= inE; i++){
            if(in[i] == rootData){
                rootIdx = i;
                break;
            }
        }
        
        int lInS = inS;
        int lInE = rootIdx - 1;
        int lPoS = poS;
        int lPoE = lInE - lInS + lPoS;
        int rInS = rootIdx + 1;
        int rInE = inE;
        int rPoS = lPoE + 1;
        int rPoE = poE - 1;
        
        root->left = helper(in, po, lInS, lInE, lPoS, lPoE);
        root->right = helper(in, po, rInS, rInE, rPoS, rPoE);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return helper(inorder, postorder, 0, n-1, 0, n-1);
    }
};