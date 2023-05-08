class Solution {
public:
    int convertStringToInt(string s){
        int ans = 0;
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(s[i] == ':'){
                continue;
            }
            ans = (ans * 10) + (s[i] - '0');
        }
        return ans;
    }
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        
        int start1 = convertStringToInt(event1[0]);
        int end1 = convertStringToInt(event1[1]);
        int start2 = convertStringToInt(event2[0]);
        int end2 = convertStringToInt(event2[1]);
        
        bool ans = false;
        if((start2 <= start1 and start1 <= end2) || (start2 <= end1 and end1 <= end2) || (start1 <= start2 and start2 <= end1) || (start1 <= end2 and end2 <= end1)){
            ans = true;
        }
        return ans;
    }
};