class Solution
{
    public:
        string countAndSay(int n)
        {

            if (n == 1) return "1";

            if (n == 2) return "11";

            string s = "11";

            for (int i = 3; i <= n; i++)
            {

                string t = "";

                int count = 0;

                char curr = ' ';

                for (int j = 0; j < s.size(); j++)
                {
                    if (curr == ' ')
                    {
                        curr = s[j];

                        ++count;
                    }
                    else if (curr == s[j])
                    {
                        ++count;
                    }
                    else if (curr != s[j])
                    {
                        t += to_string(count);

                        t.push_back(curr);

                        count = 1;

                        curr = s[j];
                    }
                }
                t += to_string(count);
                
                t.push_back(curr);
                
                s = t;
            }
            return s;
        }
};