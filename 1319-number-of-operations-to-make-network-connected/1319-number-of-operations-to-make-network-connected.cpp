class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    
    int find(int x){
        if(x == parent[x])  return x;
        return parent[x] = find(parent[x]);
    }
    
    void Union(int x, int y){
        int parent_x = find(x);
        int parent_y = find(y);
        
        if(rank[parent_x] > rank[parent_y]){
            parent[parent_y] = parent_x;
        }else if(rank[parent_x] < rank[parent_y]){
            parent[parent_x] = parent_y;
        }else{
            parent[parent_y] = parent_x;
            ++rank[parent_x];
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        parent.resize(n);
        rank.resize(n, 0);
        vector<bool>isConnected(n, false);
        
        for(int i = 0; i < n; i++)
            parent[i] = i;
        
        int extraWires = 0, maxRankElem = 0, maxRank = 0, count = 0;
        
        for(vector<int>&con : connections){            
            int u_parent = find(con[0]);
            int v_parent = find(con[1]);
            
            if(u_parent == v_parent){
                ++extraWires;
            }
            else{
                Union(con[0], con[1]);
                isConnected[con[0]] = true;
                isConnected[con[1]] = true;
            }
        }
        
        for(int i = 0; i < n; i++){
            if(parent[i] == i){
                count++;
            }
        }

        // If all computers are connected, return 0
        if(extraWires >= count - 1){
            return count - 1;
        }
        
        return -1;

        }
};