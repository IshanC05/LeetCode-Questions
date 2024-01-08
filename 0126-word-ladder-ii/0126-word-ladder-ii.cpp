class Solution {
public:
    void dfs(vector<vector<string>>& res, unordered_map<string, int>& mp, string& in, vector<string>& v) {
        if (mp[in] == 0) {
            reverse(v.begin(), v.end());
            res.push_back(v);
            reverse(v.begin(), v.end());
            return;
        }

        string s = in;

        for (int i = 0; i < in.size(); i++) {
            char original = in[i];
            for (char j = 'a'; j <= 'z'; j++) {
                in[i] = j;
                if (mp.find(in) != mp.end() && mp[s] == mp[in] + 1) {
                    v.push_back(in);
                    dfs(res, mp, in, v);
                    v.pop_back();
                }
            }
            in[i] = original;
        }
    }
    
    int helper(string beginWord, string endWord, vector<string>& wordList, unordered_map<string, int>& mp){
        unordered_set<string> st(wordList.begin(), wordList.end());

        queue<string> q;
        q.push(beginWord);
        mp[beginWord] = 0;

        while (!q.empty()) {
            string currWord = q.front();
            int steps = mp[currWord];
            q.pop();

            if (currWord == endWord) return steps + 1;

            if (st.find(currWord) != st.end()) st.erase(currWord);

            for (int i = 0; i < currWord.size(); i++) {
                char original = currWord[i];
                for (char j = 'a'; j <= 'z'; j++) {
                    currWord[i] = j;
                    if (st.find(currWord) != st.end()) {
                        q.push(currWord);
                        st.erase(currWord);
                        mp[currWord] = steps + 1;
                    }
                }
                currWord[i] = original;
            }
        }

        return 0;        
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        vector<string> v = {endWord};
        
        unordered_map<string, int> mp;
        
        int steps = helper(beginWord, endWord, wordList, mp);
        
        if(steps != 0)  dfs(res, mp, endWord, v);

        return res;
    }

};