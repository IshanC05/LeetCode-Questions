class Solution {
public:
    unordered_map<int,int>mp;
    int helper(int i, vector<int>& cost){
        
        if(i < 0)   return 0;
        
        if(i <= 1)  return cost[i];
        
        if(mp.find(i) != mp.end())
            return mp[i];
        
        return mp[i] = min(helper(i - 1, cost), helper(i - 2, cost)) + cost[i];        
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        
        mp.clear();
        
        return min(helper(n - 1, cost), helper(n - 2, cost));
    }
};