class Solution {
public:
    int minimumSum(int num) {
        vector<int>arr(4, 0);
        int i = 0;
        while(num){
            arr[i++] = num % 10;
            num = num / 10;
        }
        sort(arr.begin(), arr.end());
        int num1 = arr[0] * 10 + arr[3], num2 = arr[1]*10 + arr[2];
        return num1 + num2;
    }
};