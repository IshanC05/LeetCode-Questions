class Solution
{
    public:
        bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
        {
            int i = 0, n = popped.size();
            stack<int>st;
            for (int x: pushed) {
                st.push(x);
                while(!st.empty() and st.top() == popped[i] and i < n){
                    st.pop();
                    ++i;
                }
            }
            return i == n;
        }
};