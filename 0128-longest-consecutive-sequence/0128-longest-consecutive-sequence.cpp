class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        // if(n == 0){
        //     return n;
        // }
        unordered_map<int,bool>present,checked;
        for(int i = 0; i < n; i++){
            present[nums[i]] = true;
        }
        int longestConsecutiveSequence = 0;
        for(int i = 0; i < n; i++){
            int x = nums[i];
            if(present.find(x - 1) == present.end() and checked.find(x) == checked.end()){
                int curr = 1;
                while(present.find(x + 1) != present.end()){
                    checked[x] = true;
                    ++curr;
                    ++x;
                }
                longestConsecutiveSequence = max(longestConsecutiveSequence, curr);
            }
        }
        return longestConsecutiveSequence;
    }
};