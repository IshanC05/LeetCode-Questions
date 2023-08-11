class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int rows = matrix.size(), cols = matrix[0].size(), count = 0, ans = 0;
        
        priority_queue<int, vector<int>, greater<int>>pq;
        
        for(int i = 0; i < rows; i++){
            
            for(int j = 0; j < cols; j++){
                                
                pq.push(matrix[i][j]);
                
            }
            
        }
        
        while(--k){
            
            pq.pop();
            
        }
        
        return pq.top();
        
    }
};