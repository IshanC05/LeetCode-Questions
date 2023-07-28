class Solution
{
    public:
        int findInMountainArray(int target, MountainArray &mountainArr)
        {
            int l = 0, r = mountainArr.length() - 1;

            while (l < r)
            {
                int mid = l + (r - l) / 2;
                if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid;
                }
            }

            int peak = l;


            l = 0;
            r = peak;
            while (l < r)
            {
                int mid = l + (r - l) / 2;
                if (mountainArr.get(mid) < target)
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid;
                }
            }
            if (mountainArr.get(l) == target) return l;


            l = peak;
            r = mountainArr.length() - 1;
            while (l < r)
            {
                int mid = l + (r - l) / 2 + 1;
                if (mountainArr.get(mid) < target)
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid;
                }
            }
            return mountainArr.get(l) == target ? l : -1;
        }
};