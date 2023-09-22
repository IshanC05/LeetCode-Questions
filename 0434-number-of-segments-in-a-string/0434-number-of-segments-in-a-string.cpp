class Solution {
public:
    int countSegments(string s) {
        
        stack<string>st;
        
        string a = "";
        
        for(char i : s){
            
            if(i != ' ')    a.push_back(i);
            
            else{
                
                if(a.size() != 0)   st.push(a);
                
                a = "";
            }
            
        }
        
        if(a.size() != 0)   st.push(a);
        
        return st.size();
        
    }
};