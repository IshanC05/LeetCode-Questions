class Solution {
    public boolean dfs(Map<Integer, List<Integer>> graph, boolean[] vis, int u, int dest){
        if(u == dest)     return true;
        
        vis[u] = true;
        
        for(int v : graph.get(u)){ 
            if(!vis[v])
                 if(dfs(graph, vis, v, dest))    return true;
        }
        
        return false;
    }
    
    public boolean validPath(int n, int[][] edges, int src, int dest) {
        // build graph
        Map<Integer, List<Integer>> graph = new HashMap<>();
        
        for(int i = 0; i < edges.length; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            graph.putIfAbsent(u, new ArrayList<>());
            graph.putIfAbsent(v, new ArrayList<>());
            graph.get(u).add(v);
            graph.get(v).add(u);
        }
        
        boolean[] vis = new boolean[n];
        
        return dfs(graph, vis, src, dest);
    }
}