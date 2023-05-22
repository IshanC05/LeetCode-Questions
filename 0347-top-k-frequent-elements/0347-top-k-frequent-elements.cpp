class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        for(int i = 0; i < nums.size(); i++){
            ++mp[nums[i]];
        }
        multimap<int,int,greater<int>>mmp;
        for(auto it : mp){
            mmp.insert(make_pair(it.second, it.first));
        }
        vector<int>ans;
        for(auto it = mmp.begin(); it!= mmp.end(); it++){
            if(k == 0){
                break;
            }
            ans.push_back(it->second);
            --k;
        }
        return ans;
    }
};