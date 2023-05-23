class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool>present,checked;
        int ans = 0;
        
        for(int i : nums){
            present[i] = true;
        }
        
        for(int i : nums){
            if(present.find(i - 1) == present.end() and checked.find(i) == checked.end()){
                int curr = 0;
                int start = i;
                while(present.find(start) != present.end()){
                    checked[start] = true;
                    ++start;
                    ++curr;
                }
                ans = max(ans, curr);
            }
        }
        return ans;
    }
};