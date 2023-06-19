class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currAlt = 0, maxAlt = 0;
        for(int i : gain){
            currAlt += i;
            maxAlt = max(maxAlt, currAlt);
        }
        return maxAlt;
    }
};