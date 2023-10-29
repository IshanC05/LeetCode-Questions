class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int n = arr.size();
        int totalSum = 0;

        for (int i = 0; i < n; i++) {
            totalSum += arr[i];
        }

        if (totalSum % 3 != 0) {
            // If the total sum is not divisible by 3, we can't split it into three equal parts.
            return false;
        }

        int targetSum = totalSum / 3; // The target sum for each part.

        int currentSum = 0;
        int partsFound = 0;

        for (int i = 0; i < n - 1; i++) {
            currentSum += arr[i];

            if (currentSum == targetSum) {
                partsFound++;
                currentSum = 0;
            }

            if (partsFound == 2) {
                // If we've found two parts with the target sum, the third part will have the same sum.
                return true;
            }
        }

        return false;
    }

};