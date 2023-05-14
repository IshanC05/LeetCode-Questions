class Solution {
public:
    bool checkString(string s) {
        int firstIdxB = -1, lastIdxA = -1;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'b' and firstIdxB == -1){
                firstIdxB = i;
            }
            if(s[i] == 'a'){
                lastIdxA = i;
            }
        }
        if(firstIdxB == -1 || lastIdxA == -1 || firstIdxB > lastIdxA){
            return true;
        }
        return false;
    }
};