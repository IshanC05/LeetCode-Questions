class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int>factors;
        for(int i = 1; i <= n; i++){
            if(n % i == 0){
                factors.push_back(i);
            }
        }
        // factors.push_back(n);
        int sz = factors.size();
        if(k > sz){
            return -1;
        }
        return factors[--k]; 
    }
};