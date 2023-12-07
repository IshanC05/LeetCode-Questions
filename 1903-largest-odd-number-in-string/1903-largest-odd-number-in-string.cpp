class Solution {
public:
    bool check(int x){
        return (x % 2 == 1) ? true : false;
    }
    
    string largestOddNumber(string num) {
        
        int i = num.size() - 1;
        
        while(i >= 0 && !check(num[i] - '0'))   --i;
        
        if(i < 0)   return "";
        
        return num.substr(0, i + 1);
        
    }
};