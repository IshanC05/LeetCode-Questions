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
            parent[parent_x] = parent_y;
            ++rank[parent_y];
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        parent.resize(n);
        rank.resize(n, 0);
        
        for(int i = 0; i < n; i++)
            parent[i] = i;
        
        if(connections.size() < n - 1)
            return -1;
        
        int components = n;
        
        for(auto& con : connections){
            if(find(con[0]) != find(con[1])){
                Union(con[0], con[1]);
                --components;
            }
        }
        
        return components - 1;
    }
};