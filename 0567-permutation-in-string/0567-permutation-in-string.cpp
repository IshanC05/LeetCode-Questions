class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>mainFreq(26, 0), currFreq(26, 0);
        for(int i = 0; i < s1.size(); i++){
            ++mainFreq[s1[i] - 'a'];
        }
        int i = 0, j = 0, n = s2.size();
        while(j < n){
            if(j - i + 1 <= s1.size()){
                ++currFreq[s2[j] - 'a'];
                ++j;
            }else{
                --currFreq[s2[i] - 'a'];
                ++i;
            }
            bool curr = true;
            for(int i = 0; i < 26; i++){
                if(mainFreq[i] != currFreq[i]){
                    curr = false;
                }
            }
            if(curr){
                return true;
            }
        }
        return false;
    }
};