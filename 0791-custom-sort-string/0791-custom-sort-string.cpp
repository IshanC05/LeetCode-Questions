class Solution {
public:
    string customSortString(string order, string s) {
        vector<int>freq(26, 0);
        
        for(char i : s)   
            ++freq[i - 'a'];
        
        string res;
        
        for(char i : order){
            while(freq[i - 'a'] != 0){
                res.push_back(i);
                --freq[i - 'a'];
            }
        }
        
        for(int i = 0; i < 26; i++){
            while(freq[i] != 0){
                res.push_back((char)(i + 'a'));
                --freq[i];
            }
        }
        
        return res;
    }
};