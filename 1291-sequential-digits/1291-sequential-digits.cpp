class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string start = to_string(low), end = to_string(high);
        string digits = "123456789";
        
        vector<int>res;
        set<int>st;
        
        for(int len = start.length(); len <= end.length(); len++){
            for(int i = 0; i < digits.length() - len + 1; i++){
                string temp = digits.substr(i, len);
                st.insert(stoi(temp));
            }
        }
        
        for(auto it : st){
            if(it >= low && it <= high){
                res.push_back(it);
            }
        }
        
        return res;
    }
};