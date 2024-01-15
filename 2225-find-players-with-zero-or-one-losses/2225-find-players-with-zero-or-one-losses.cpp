class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int>players;
        
        for(vector<int>match : matches){
            ++players[match[1]];
        }
        
        for(vector<int>match : matches){
            if(players.find(match[0]) == players.end())     players.insert({match[0], 0});
        }
        
        vector<int>win, lose;
        
        for(auto it : players){            
            if(it.second == 0)
                win.push_back(it.first);
            
            if(it.second == 1)
                lose.push_back(it.first);
        }
        
        sort(win.begin(), win.end());
        sort(lose.begin(), lose.end());
        
        return {win, lose};
    }
};