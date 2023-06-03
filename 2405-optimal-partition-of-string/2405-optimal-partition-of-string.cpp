class Solution {
public:
    int partitionString(string s) {
        unordered_set<char>freq;
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            if(freq.find(s[i]) == freq.end()){
                freq.insert(s[i]);
            }else{
                ++count;
                freq.clear();
                freq.insert(s[i]);
            }
        }
        if(!freq.empty()){
            ++count;
        }
        return count;
    }
};