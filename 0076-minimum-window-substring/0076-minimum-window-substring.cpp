class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) {
            return "";
        }

        unordered_map<char, int> targetFreq;
        for (char ch : t) {
            ++targetFreq[ch];
        }

        int requiredChars = t.size();
        int minLen = INT_MAX;
        int startIndex = 0;
        int left = 0;

        for (int right = 0; right < s.size(); ++right) {
            if (targetFreq[s[right]] > 0) {
                --requiredChars;
            }
            --targetFreq[s[right]];

            while (requiredChars == 0) {
                int currentLen = right - left + 1;
                if (currentLen < minLen) {
                    minLen = currentLen;
                    startIndex = left;
                }

                ++targetFreq[s[left]];
                if (targetFreq[s[left]] > 0) {
                    ++requiredChars;
                }
                ++left;
            }
        }

        if (minLen == INT_MAX) {
            return "";
        }

        return s.substr(startIndex, minLen);
    }

};