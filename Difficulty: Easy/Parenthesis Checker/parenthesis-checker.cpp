//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    bool isBalanced(string& s) {
        // code here
        stack<char>st;
        // if(s[0] == ')' || s[0] == '}' || s[0] == ']') return false;
        // st.push(s[0]);
        
        for(char c : s){
            if(c == '(' || c == '{' || c == '['){
                st.push(c);
            }
            
            else{
                
                if(st.empty()) return false;
                
                char top = st.top();
                
                if ((c == ')' && top == '(') || (c == '}' && top == '{') || (c == ']' && top == '[')) 
                
                st.pop();
                
                else{
                    return false;
                }

            }
        }
        return st.empty();
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends