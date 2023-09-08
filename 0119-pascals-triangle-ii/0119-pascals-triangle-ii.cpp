class Solution {
public:
    vector<int> getRow(int idx) {
            
        int i = 0;
        
        vector<int>start({1});
        
        while(i <= idx){
            
            vector<int>temp({1});
            
            for(int j = 1; j < i; j++){
                
                temp.push_back(start[j - 1] + start[j]);
                
            }
            
            if(i != 0)  temp.push_back(1);
            
            start = temp;
            
            ++i;
        }
        
        return start;
        
    }
};