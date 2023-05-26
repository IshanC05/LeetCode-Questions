class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size(), i = 0, j = n - 1, ans = 0;
        
        while(i <= j){
            int sum = people[i] + people[j];
            if(sum <= limit){
                ++i;
                --j;
            }else if(sum > limit){
                --j;
            }
            ++ans;
        }
        return ans;
    }
};