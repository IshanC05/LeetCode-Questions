class Solution
{
    public:
        int leastBricks(vector<vector < int>> &wall)
        {
            unordered_map < long long, long long > mp;
            for (int i = 0; i < wall.size(); i++)
            {
                int curDistance = 0;
                for (int j = 0; j < wall[i].size() - 1; j++)
                {
                    curDistance = curDistance + wall[i][j];
                    ++mp[curDistance];
                }
            }
            int rows = wall.size();
            int minCuts = rows;
            for (auto it: mp)
            {
                int distance_of_crack = it.first;
                int number_of_rows_crack_present_in = it.second;
                minCuts = min(minCuts, (rows - number_of_rows_crack_present_in));
            }
            return minCuts;
        }
};