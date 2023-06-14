class Solution {
public:
    bool isVowel(char d){
        if(d == 'A' || d == 'E' || d == 'I' || d == 'O' || d == 'U' || d == 'a' || d == 'e' || d == 'i' || d == 'o' || d == 'u'){
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        stack<char>st;
        for(char x : s){
            if(isVowel(x)){
                st.push(x);
            }
        }
        
        for(int i = 0; i < s.size(); i++){
            if(isVowel(s[i])){
                s[i] = st.top();
                st.pop();
            }
        }
        
        return s;
    }
};