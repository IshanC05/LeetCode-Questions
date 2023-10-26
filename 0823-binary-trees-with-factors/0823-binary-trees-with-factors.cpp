class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int mod = 1e9+7;
        
        unordered_map<int,long long>mp;
        
        sort(arr.begin(), arr.end());
        
        mp[arr[0]] = 1;
        
        int n = arr.size();
        
        for(int i = 1; i < n; i++){
            
            int root = arr[i];
            
            mp[root] = 1;
            
            for(int j = 0; j < i; j++){
                
                int leftChild = arr[j];
                
                int rightChild = root / leftChild;
                
                if((root % leftChild == 0) && mp.find(rightChild) != mp.end()){
                    
                    mp[root] += (mp[leftChild] *(1LL)* mp[rightChild]);
                    
                }
                
            }
            
        }
        
        long long res = 0;
        
        for(auto it : mp)
            res += it.second;
        
        return (res % mod);
    }
};