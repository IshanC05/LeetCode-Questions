class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
       int currP = 0, prevP = 0;
       int start = 0;
       
       for(int i = 0; i < cost.size(); i++){
           
           currP += (gas[i] - cost[i]);
           
           if(currP < 0){
               start = i + 1;
               prevP += currP;
               currP = 0;
           }
           
       }
       
       return (currP + prevP) >= 0 ? start : -1;
        
    }
};