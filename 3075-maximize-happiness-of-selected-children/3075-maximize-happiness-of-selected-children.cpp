class Solution {
public:
    long long maximumHappinessSum(vector<int>& arr, int k) {
        int n = arr.size();
        long long res = 0;
        int dec = 0;
        int i = 0;

        sort(arr.rbegin(), arr.rend());

        while (k-- && i < n) {
            long long prevRes = res;
            res += max(arr[i] - dec, 0);
            ++dec;
            ++i;
            if (prevRes == res)
                break;
        }

        return res;
    }
};