//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
         int n = arr.size();

        // vector<int>duplicate;

        // for(int i = 0 ; i < 2*n; i++){
        //     duplicate.push_back(arr[i % n]);
        // }

        vector<int>ans(n,-1);
        stack<int>st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[i] > arr[st.top()]){
                int idx = st.top();
                st.pop();
                ans[idx] = arr[i];
            }

            st.push(i);  // because of ans er size n deoya ace but just i dile index er value n er bahire jete pare
        }

        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after reading t
    while (t--) {
        vector<int> a;
        string input;

        // Reading the entire input line for the array
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num); // Read the array elements from input string

        Solution obj;
        vector<int> result = obj.nextLargerElement(a);

        // Print the result in the required format
        for (int i = 0; i < result.size(); i++) {
            if (i != 0)
                cout << " ";
            cout << result[i];
        }
        cout << endl;        // Ensure new line after each test case output
        cout << "~" << endl; // Ensure new line after each test case output
    }

    return 0;
}

// } Driver Code Ends