class Solution {
public:
    int minimumPartition(string s, int k) {
        int count = 1;
        string temp = "";
        for(int i = 0; i < s.size(); i++){
            temp.push_back(s[i]);
            long long val = stoll(temp);
            if(val <= k){
                //  do nothing
            }else{
                ++count;
                temp = s[i];
                if(s[i] - '0' > k){
                    return -1;
                }
            }
        }
        return count;
    }
};