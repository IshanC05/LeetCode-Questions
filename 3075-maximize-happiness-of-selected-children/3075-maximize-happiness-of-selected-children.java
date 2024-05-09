class Solution {
    public long maximumHappinessSum(int[] arr, int k) {
        int n = arr.length;
        long res = 0;
        int dec = 0;
        int i = 0;

        Arrays.sort(arr);
        reverse(arr);

        while (k-- > 0 && i < n) {
            long prevRes = res;
            res += Math.max(arr[i] - dec, 0);
            ++dec;
            ++i;
            if (prevRes == res)
                break;
        }

        return res;
    }

    private void reverse(int[] arr) {
        int start = 0;
        int end = arr.length - 1;
        while (start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }
}