/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)   return "N";
        
        string s;
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            
            TreeNode* f = q.front();
            q.pop();
            
            if(f != NULL)   
                s = s + to_string(f->val);
            else    
                s.push_back('N');
                
            s.push_back(',');
            
            if(f){
                if(f->left)     q.push(f->left);
                else    q.push(NULL);    
                    
                if(f->right)    q.push(f->right);
                else    q.push(NULL);
            }            
        }
        
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data[0] == 'N')  return NULL;
        
        int i = 0, n = data.size();
        string value;
        
        while(i < n && data[i] != ',')  value.push_back(data[i++]);
        ++i;
        
        TreeNode* root = new TreeNode(stoi(value));
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
        
            int qSize = q.size();
            
            for(int k = 0; k < qSize; k++){
                
                TreeNode* front = q.front();
                q.pop();
                
                value = "";
                
                while(i < n && data[i] != ',')  value.push_back(data[i++]);
                ++i;
                
                if(value == "N")    front->left = NULL;
                else{
                    front->left = new TreeNode(stoi(value));
                    q.push(front->left);
                }
                
                value = "";
                
                while(i < n && data[i] != ',')  value.push_back(data[i++]);
                ++i;
                
                if(value == "N")    front->right = NULL;
                else{
                    front->right = new TreeNode(stoi(value));
                    q.push(front->right);
                }
            }            
        }
        
        return root;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));