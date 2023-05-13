class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int count = 0;
        unordered_map<int,bool>mp;
        vector<int>ans;
        for(int i = 0; i < A.size(); i++){
            if(A[i] == B[i]){
                ++count;
            }else{
                if(mp.find(A[i]) != mp.end()){
                    ++count;
                }
                if(mp.find(B[i]) != mp.end()){
                    ++count;
                }
                mp[A[i]] = true;
                mp[B[i]] = true;
            }
            ans.push_back(count);
        }
        return ans;
    }
};