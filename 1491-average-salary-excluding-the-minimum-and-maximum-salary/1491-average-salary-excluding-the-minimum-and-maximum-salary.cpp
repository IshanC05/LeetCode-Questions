class Solution {
public:
    double average(vector<int>& salary) {
        int size = salary.size(), m = salary[0], n = salary[0], sum = salary[0];
        for(int i = 1; i < size; i++){
            sum = sum + salary[i];
            m = max(m, salary[i]);
            n = min(n, salary[i]);
        }
        sum = sum - m - n;
        size = size - 2;
        return (sum / (size * 1.0));
    }
};