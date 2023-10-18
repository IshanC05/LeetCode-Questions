/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    map<int, map<int, multiset<int>>> nodes;
    
    void inorder(TreeNode* root, int level, int vertical){
        
        if(!root)   return;
        
        inorder(root->left, level + 1, vertical - 1);
        
        nodes[vertical][level].insert(root->val);
        
        inorder(root->right, level + 1, vertical + 1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        nodes.clear();

        inorder(root, 0, 0);

        vector<vector<int>> ans;

        for (auto v : nodes) {
            vector<int> smallAns;

            for (auto col : v.second) {
                smallAns.insert(smallAns.end(), col.second.begin(), col.second.end());
            }

            ans.push_back(smallAns);
        }

        return ans;
    }
};