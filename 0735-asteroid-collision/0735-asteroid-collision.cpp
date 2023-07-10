class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        int i = 0, n = asteroids.size();
        
        stack<int>st;
        
        while(i < n){
            
            if(st.empty() || asteroids[i] > 0){
                st.push(asteroids[i]);
            }
            else{
                
                while(!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i])){
                    st.pop();
                }
                
                if(st.empty() || st.top() < 0){
                    st.push(asteroids[i]);
                }
                
                else if(!st.empty() && st.top() > 0 && st.top() == abs(asteroids[i])){
                    st.pop();
                }
                
            }
            
            ++i;
        }
        
        vector<int>ans;
        
        while(!st.empty()){
            
            ans.push_back(st.top());
            
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};