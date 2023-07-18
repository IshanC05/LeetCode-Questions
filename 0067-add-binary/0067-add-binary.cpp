class Solution {
public:
    string addBinary(string a, string b) {
        
        reverse(a.begin(), a.end());
        
        reverse(b.begin(), b.end());
        
        int m = a.size(), n = b.size();
        
        int i = 0, j = 0, carry = 0;
        
        string ans = "";
        
        while(i < m || j < n || carry){
            
            int a1 = (i < m) ? a[i++] - '0' : 0;
            
            int b1 = (j < n) ? b[j++] - '0' : 0;
            
            int sum = a1 + b1 + carry;
            
            carry = sum / 2;
            
            sum = sum % 2;
            
            ans.push_back(sum + '0');
            
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
        
    }
};