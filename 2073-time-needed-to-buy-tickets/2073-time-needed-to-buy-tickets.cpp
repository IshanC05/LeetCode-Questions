class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        vector<int> res(n, 0);
        
        queue<pair<int, int>> q;
        
        for(int i = 0; i < n; i++){
            q.push(make_pair(tickets[i], i));
        }
        
        int time = 0;
        
        while(res[k] == 0){
            int qSize = q.size();
            
            for(int i = 0; i < qSize; i++){
                auto p = q.front();
                q.pop();
                
                --p.first;
                
                ++time;
                
                if(p.first == 0){
                    res[p.second] = time;
                }else{
                    q.push(p);
                }
            }
        }
        
        return res[k];
    }
};