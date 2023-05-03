class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>ans;
        set<int>set1(nums1.begin(), nums1.end());
        set<int>set2(nums2.begin(), nums2.end());
        vector<int>ansSet;
        for(auto it = set1.begin(); it != set1.end(); it++){
            if(set2.find(*it) == set2.end()){
                ansSet.push_back(*it);
            }
        }
        ans.push_back(ansSet);
        ansSet.clear();
        for(auto it = set2.begin(); it != set2.end(); it++){
            if(set1.find(*it) == set1.end()){
                ansSet.push_back(*it);
            }
        }
        ans.push_back(ansSet);
        return ans;
    }
};