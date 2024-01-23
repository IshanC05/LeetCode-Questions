class Solution {
public:
    int used[26];
    bool isValid(string &s){
        unordered_set<char>st;
        for(char i : s)
            st.insert(i);
        return st.size() == s.size();
    }
    
    bool check(string s){
        for(char i : s){
            if(used[i - 'a'] + 1 > 1)   return false;
        }
        return true;
    }
    
    void mark(string s, bool val){
        for(char i : s){
            if(val)     ++used[i - 'a'];
            else    --used[i - 'a'];
        }
    }
    
    int helper(vector<string>& arr, int idx){
        if(idx >= arr.size())   return 0;
        
        int take = 0, skip = 0;
        
        if(isValid(arr[idx]) && check(arr[idx])){
            skip = helper(arr, idx + 1);
            mark(arr[idx], true);
            take = arr[idx].size() + helper(arr, idx + 1);
            mark(arr[idx], false);
        }else{
            skip = helper(arr, idx + 1);
        }
            
        return max(take, skip);
    }
    
    int maxLength(vector<string>& arr) {
        for(int i = 0; i < 26; i++)
            used[i] = 0;
        return helper(arr, 0);
    }
};