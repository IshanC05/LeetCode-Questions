class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int>mainCounter(26, 0);
        string start = words[0];
        for(char i : start){
            ++mainCounter[i - 'a'];
        }
        for(int i = 1; i < words.size(); i++){
            vector<int>temp(26, 0);
            string word = words[i];
            
            for(char j : word){
                ++temp[j - 'a'];
            }
            
            for(int k = 0; k < 26; k++){
                mainCounter[k] = min(mainCounter[k], temp[k]);
            }
        }
        
        vector<string>ans;
        for(int i = 0; i < 26; i++){
            while(mainCounter[i]--){
                string t = "";
                char d = i + 'a';
                t.push_back(d);
                ans.push_back(t);
            }
        }
        return ans;
    }
};