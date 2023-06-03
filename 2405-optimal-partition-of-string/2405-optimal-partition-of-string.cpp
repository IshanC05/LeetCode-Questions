class Solution {
public:
    int partitionString(string s) {
        vector<int>freq(26, 0);
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            int asc = s[i] - 'a';
            if(freq[asc] == 1){
                ++count;
                for(int i = 0; i < 26; i++){
                    freq[i] = 0;
                }
            }
            freq[asc] = 1;
        }
        bool flag = 0;
        for(int i = 0; i < 26; i++){
            if(freq[i] != 0){
                flag = 1;
            }
        }
        if(flag){
            ++count;
        }
        return count;
    }
};