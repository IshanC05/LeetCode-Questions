class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(), wordList.end());
        
        queue<pair<string, int>>q;
        q.push({beginWord, 1});
        
        while(!q.empty()){
            
            string u = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            if(u == endWord)    return steps;
            
            if(st.find(u) != st.end())  st.erase(u);
            
            for(int i = 0; i < u.size(); i++){
                
                char original = u[i];
                for(char j = 'a'; j <= 'z'; j++){
                    
                    u[i] = j;
                    if(st.find(u) != st.end()){
                        st.erase(u);
                        q.push({u, 1 + steps});
                    }
                    
                }
                
                u[i] = original;
            }
        }
        
        return 0;
    }
};