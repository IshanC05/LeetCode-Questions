class Solution {
public:
    bool static cmp(pair<int,int>a, pair<int,int>b){
        if(a.first != b.first)  return a.first < b.first;
        return a.second < b.second;        
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        int m = mat.size(), n = mat[0].size();
        vector<pair<int,int>>row_one_count;
        
        for(int i = 0; i < m ; i++){
            
            int count = 0;
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0)  break;
                else    ++count;                
            }
            
            row_one_count.push_back({count, i});            
        }
        
        sort(row_one_count.begin(), row_one_count.end(), cmp);
        
        vector<int>ans;
        
        for(int i = 0; i < k; i++){
            ans.push_back(row_one_count[i].second);
        }
        
        return ans;
    }
};