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
                
                bool flag = false;
                
                while(!st.empty() && st.top() > 0 && st.top() <= abs(asteroids[i])){
                    
                    int top = st.top();
                    
                    st.pop();
                    
                    if(top == abs(asteroids[i])){
                        
                        ++i;
                        
                        flag = true;
                        
                        break;
                    }
                    
                }
                
                if(flag){
                    
                    continue;
                    
                }
                
                if(st.empty() || st.top() < 0){
                    st.push(asteroids[i]);
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