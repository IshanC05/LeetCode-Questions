class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int>players, winners;
        map<int, int>loosers;
        
        for(vector<int>match : matches){
            winners.insert(match[0]);
            ++loosers[match[1]];
            
            players.insert(match[0]);
            players.insert(match[1]);
        }
        
        vector<int>win, lose;
        
        for(auto it : players){            
            if(loosers.find(it) == loosers.end())
                win.push_back(it);
        }
        
        for(auto it : loosers){
            if(it.second == 1)  
                lose.push_back(it.first);
        }
        
        return {win, lose};
    }
};