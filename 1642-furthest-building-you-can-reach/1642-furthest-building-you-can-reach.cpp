class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        priority_queue<int>pq;
        int n = h.size();
        
        for(int i = 0; i < n - 1; i++){
            int d = h[i + 1] - h[i];
            if(d <= 0)  continue;
            pq.push(d);
            
            bricks -= d;
            
            if(bricks < 0){
                if(ladders > 0){
                    --ladders;
                    bricks += pq.top();
                    pq.pop();
                }
                else    return i;
            }
            
        }
        
        return n - 1;
    }
};