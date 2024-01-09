class Solution {
public:
    static bool cmp(string &a, string &b){
        if(a == b)  return true;
        if(a.length() != b.length())    return a.length() < b.length();
        
        for(int i = 0; i < a.length(); i++){
            if(a[i] != b[i])     return a[i] < b[i];    
        }
        return false;
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        unordered_map<string, int>mp;
        
        for(string s : nums)
            ++mp[s];
        
        vector<string>temp;
        
        for(auto it : mp)
            temp.push_back(it.first);
            
        sort(temp.begin(), temp.end(), cmp);
        
        int i = 0, j = 0;
        
        while(i < temp.size()){
            while(mp[temp[i]]){
                nums[j++] = temp[i];
                --mp[temp[i]];
                
                if(mp[temp[i]] == 0)    mp.erase(temp[i]);
            }
            ++i;
        }
        
        return nums[nums.size() - k];
    }
};