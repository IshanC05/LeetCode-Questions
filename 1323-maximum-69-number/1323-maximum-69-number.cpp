class Solution {
public:
    int maximum69Number (int num) {
        stack<int>st;
        while(num){
            st.push(num % 10);
            num = num / 10;
        }
        int ans = 0, digit = 9;
        while(!st.empty()){
            int t = st.top();
            st.pop();
            if(t == 6 and digit != 0){
                t = digit;
                digit = 0;
            }
            ans = ans * 10 + t;
        }
        return ans;
    }
};