class Solution {
public:
    int maxVowels(string s, int k) {
        int i = 0, j = 0, n = s.size(), res = 0;
        vector<int>freq(26, 0);
        // a->0 e->4 i->8 o->14 u->20
        while(j < n){
            while(j < n and (j - i + 1  <= k)){
                ++freq[s[j] - 'a'];
                ++j;
            }
            int curr = freq[0] + freq[4] + freq[8] + freq[14] + freq[20];
            res = max(res, curr);
            while(j - i + 1 > k){
                --freq[s[i] - 'a'];
                ++i;
            }
        }
        return res;
    }
};