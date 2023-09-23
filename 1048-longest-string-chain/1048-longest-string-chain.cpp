class Solution {
public:
    bool static cmp(const string &s1, const string &s2) {
        return s1.length() < s2.length();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        if (n <= 1) return n; 

        sort(words.begin(), words.end(), cmp);

        unordered_map<string, int> chainLength; 

        int maxLength = 1; 

        for (const string& word : words) {
            chainLength[word] = 1; 

            for (int i = 0; i < word.size(); ++i) {
                string predecessor = word.substr(0, i) + word.substr(i + 1);

                if (chainLength.find(predecessor) != chainLength.end()) {

                    chainLength[word] = max(chainLength[word], chainLength[predecessor] + 1);
                }
            }

            maxLength = max(maxLength, chainLength[word]);
        }

        return maxLength;
    }
};