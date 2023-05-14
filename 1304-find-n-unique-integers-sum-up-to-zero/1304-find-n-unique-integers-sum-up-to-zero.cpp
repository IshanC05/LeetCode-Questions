class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans(n, 0);
        int i = (n % 2 == 0) ? 0 : 1;
        int j = 1;
        bool flag = true;
        for(; i < n; i++){
            if(flag == true){
                ans[i] = j;
            }else{
                ans[i] = (-1) * j;
                ++j;
            }
            flag = !flag;
        }
        return ans;
    }
};