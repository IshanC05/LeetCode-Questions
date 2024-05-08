class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < score.size(); i++) {
            pq.push({score[i], i});
        }

        vector<string> res(score.size());

        int i = 1;

        while (!pq.empty()) {
            auto pair = pq.top();
            pq.pop();

            int idx = pair.second;

            if (i == 1)
                res[idx] = "Gold Medal";
            else if (i == 2)
                res[idx] = "Silver Medal";
            else if (i == 3)
                res[idx] = "Bronze Medal";
            else
                res[idx] = to_string(i);

            ++i;
        }

        return res;
    }
};