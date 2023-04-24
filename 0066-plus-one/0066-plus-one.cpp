class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits[digits.size() - 1] < 9){
            ++digits[digits.size() - 1];
            return digits;
        }
        reverse(digits.begin(), digits.end());
        digits[0] = 0;
        int carry = 1, i = 1;
        while(i < digits.size() and carry != 0){
            digits[i] = digits[i] + carry;
            carry = 0;
            if(digits[i] > 9){
                digits[i] = 0;
                carry = 1;
            }
            ++i;
        }
        if(carry){
            digits.push_back(carry);
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};