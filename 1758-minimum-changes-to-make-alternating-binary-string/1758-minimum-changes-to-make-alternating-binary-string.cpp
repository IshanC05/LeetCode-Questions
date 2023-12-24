class Solution {
public:
    int minOperations(string s) {
        int start1 = 0;
        
        for(int i = 0; i < s.size(); i++){
            
            if(i % 2 == 0 && s[i] == '0')   ++start1;
            
            else if(i % 2 != 0 && s[i] == '1')  ++start1;
            
        }
        
        return min(start1, (int)s.size() - start1);
    }
};