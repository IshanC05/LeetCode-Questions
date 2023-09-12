class Solution {
public:
    
    bool isUnique(vector<int>&freq, int c, int idx){
        
        bool ans = true;
        
        for(int i = 0; i < 26; i++){
            
            if(i == idx)    continue;
            
            if(freq[i] == c)    ans = false;
        }
        
        return ans;        
    }
    
    int minDeletions(string s) {
        
        vector<int>freq(26, 0);
        
        for(int i = 0; i < s.size(); i++){
            ++freq[s[i] - 'a'];
        }
        
        int count = 0;
        
        for(int i = 0; i < 26; i++){
            
            while(freq[i] != 0 && isUnique(freq, freq[i], i) == false){
                --freq[i];
                ++count;
            }
            
        }
        
        return count;
        
    }
};