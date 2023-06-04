class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(256, 0);
        int minLength = INT_MAX;
        int start = 0, end = 0;
        int count = t.size();

        for (char c : t) {
            freq[c]++;
        }

        int i = 0, j = 0, n = s.size();
        while (j < n) {
            if (freq[s[j]] > 0) {
                count--;
            }
            freq[s[j]]--;
            j++;

            while (count == 0) {
                if (j - i < minLength) {
                    minLength = j - i;
                    start = i;
                    end = j;
                }

                freq[s[i]]++;
                if (freq[s[i]] > 0) {
                    count++;
                }
                i++;
            }
        }

        if (minLength == INT_MAX) {
            return "";
        }

        return s.substr(start, end - start);
    }

};