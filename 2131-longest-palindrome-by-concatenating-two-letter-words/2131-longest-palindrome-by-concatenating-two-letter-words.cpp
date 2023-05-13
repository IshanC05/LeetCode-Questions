class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int res = 0;
        bool flag = false;
        unordered_map<string,int>mp;
        for(string word : words){
            ++mp[word];
        }
        
        for(string word : words){
            if(word[0] != word[1]){
                string revWord = "";
                revWord.push_back(word[1]);
                revWord.push_back(word[0]);
                if(mp.find(revWord) != mp.end()){
                    res += min(mp[revWord], mp[word]) * 4;
                    mp.erase(revWord);
                    mp.erase(word);
                }
            }else{
                int count = mp[word];
                if(count % 2 == 0){
                    res += count * 2;
                }else{
                    if(flag == false){
                        res += count * 2;
                        flag = true;
                    }else{
                        res += (count - 1) * 2;
                    }
                }
                mp.erase(word);
            }
        }
        return res;
    }
};