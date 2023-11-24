class Solution {
public:
    int maxCoins(vector<int>& piles) {
        
        sort(piles.begin(), piles.end());
        
        int n = piles.size();
        
        int l = 0, r = n - 2, res = 0;
        
        while(l < r){
            
            res += piles[r];
            
            r -= 2;
            
            ++l;
            
        }
        
        return res;
        
    }
};