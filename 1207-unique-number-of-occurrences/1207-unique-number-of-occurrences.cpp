class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int>freq(2005, 0);
        
        for(int i : arr){
            if(i < 0)   i = abs(i) + 1000;
            ++freq[i];
        }
        
        sort(freq.begin(), freq.end());
        
        for(int i = 1; i < freq.size(); i++){
            if(freq[i - 1] == freq[i] && freq[i] != 0)  return false;
        }
        
        return true;
    }
};