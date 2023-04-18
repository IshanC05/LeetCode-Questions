class Solution
{
    public:
        int minAddToMakeValid(string s)
        {
            if(s.size() == 0){
                return s.size();
            }
            stack<char> st;
            for (int i = 0; i < s.size(); i++)
            {
                if (st.empty())
                {
                    st.push(s[i]);
                }
                else if (s[i] == '(')
                {
                    st.push(s[i]);
                }
                else
                {
                    if (st.top() == '(')
                    {
                        st.pop();
                    }
                    else
                    {
                        st.push(s[i]);
                    }
                }
            }
            return st.size();
        }
};