class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        
        vector<int>freq(26, 0);
        
        for(string word : words){
            for(char i : word){
                ++freq[i - 'a'];
            }
        }
        
        for(int i = 0; i < 26; i++){
            if(freq[i] != 0 && freq[i] % n != 0)  return false;
        }
        
        return true;
    }
};