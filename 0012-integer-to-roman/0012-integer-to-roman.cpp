class Solution
{
    public:
        string intToRoman(int num)
        {
            string Roman = "";
            vector<pair<int, string>> storeIntRoman
            {
                make_pair(1000, "M"),
                    make_pair(900, "CM"),
                    make_pair(500, "D"),
                    make_pair(400, "CD"),
                    make_pair(100, "C"),
                    make_pair(90, "XC"),
                    make_pair(50, "L"),
                    make_pair(40, "XL"),
                    make_pair(10, "X"),
                    make_pair(9, "IX"),
                    make_pair(5, "V"),
                    make_pair(4, "IV"),
                    make_pair(1, "I")
            };
            for (int i = 0; i < storeIntRoman.size(); i++)
            {
                while (num >= storeIntRoman[i].first)
                {
                    Roman += storeIntRoman[i].second;
                    num -= storeIntRoman[i].first;
                }
            }
            return Roman;
        }
};