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
    bool BFS(TreeNode* root){
        
        queue<TreeNode*>q;
        q.push(root);
        
        int level = 0;
        bool ans = true;
        
        while(!q.empty()){
            
            int qSize = q.size();
            vector<int>temp;
            
            for(int i = 0; i < qSize; i++){
                
                TreeNode* front = q.front();
                q.pop();
                
                temp.push_back(front->val);
                
                if(front->left)     q.push(front->left);
                if(front->right)    q.push(front->right);
                
            }
            
            if(level % 2 == 0){
                
                for(int i = 0; i < qSize; i++){
                    
                    if(temp[i] % 2 != 0){
                        
                        if(i + 1 < qSize){
                        
                            if(temp[i] >= temp[i + 1] || temp[i + 1] % 2 == 0)     ans = false; 
                            
                        }
                        
                    }else{
                        ans = false; 
                    }
                    
                }
                
            }else{
                
                for(int i = 0; i < qSize; i++){
                    
                    if(temp[i] % 2 == 0){
                        
                        if(i + 1 < qSize){
                        
                            if(temp[i] <= temp[i + 1] || temp[i + 1] % 2 != 0)     ans = false; 
                            
                        }
                        
                    }else{
                        ans = false; 
                    }
                    
                }
                
            }
            
            if(!ans)    return ans;
            
            ++level;
            
        }
        
        return ans;
        
    }
    bool isEvenOddTree(TreeNode* root) {
        
        if(!root)   return true;
        
        return BFS(root);
    }
};