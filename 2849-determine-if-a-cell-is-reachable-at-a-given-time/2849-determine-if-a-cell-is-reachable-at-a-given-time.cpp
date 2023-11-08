class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        
        int a = abs(fx - sx);
        
        int b = abs(fy - sy);
        
        int minTime = max(a, b);
        
        if(minTime == 0)    return !(t == 1);
        
        return minTime <= t;        
    }
};