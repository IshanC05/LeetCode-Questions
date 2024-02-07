class Solution {
public:
    string frequencySort(string s) {
        vector<int>freq(128, 0);
        
        for(char i : s)   ++freq[i];
        
        priority_queue<pair<int, char>>pq;
        
        for(int i = 0; i < 128; i++){
            if(freq[i] != 0){
                pq.push({freq[i], (char)i});
            }
        }
        
        string res;
        
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            
            string temp(top.first, top.second);
            
            res = res + temp;
        }
        
        return res;
    }
};