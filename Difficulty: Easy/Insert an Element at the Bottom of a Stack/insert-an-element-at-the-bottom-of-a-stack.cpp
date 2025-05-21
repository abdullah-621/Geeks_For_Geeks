// User function Template for C++

class Solution {
  public:
    stack<int> insertAtBottom(stack<int> st, int x) {
        
        stack<int>temp;
        
        while(!st.empty()){
            int val = st.top();
            st.pop();
            temp.push(val);
        }
        
        st.push(x);
        
        while(!temp.empty()){
            int val = temp.top();
            temp.pop();
            st.push(val);
        }
        
        return st;
    }
};