class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int>freq(26, 0);
        for(int i = 0; i < words[0].size(); i++){
            ++freq[words[0][i] - 'a'];
        }
        for(int i = 1; i < words.size(); i++){
            string temp = words[i];
            vector<int>tempFreq(26, 0);
            for(int j = 0; j < temp.size(); j++){
                ++tempFreq[temp[j] - 'a'];
            }
            for(int k = 0; k < 26; k++){
                freq[k] = min(freq[k], tempFreq[k]);
            }
        }
        vector<string>ans;
        for(int i = 0; i < 26; i++){
            while(freq[i]--){
                string t = "";
                t.push_back((char)(i + 'a'));
                ans.push_back(t);
            }
        }
        return ans;
    }
};