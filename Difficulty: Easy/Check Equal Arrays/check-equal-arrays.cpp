//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    // Function to check if two arrays are equal or not.
    bool checkEqual(vector<int>& a, vector<int>& b) {
        // code here
        // sort(a.begin(),a.end());
        // sort(b.begin(),b.end());
        
        // for(int i = 0; i < a.size(); i++){
        //     if(a[i] != b[i]){
        //         return false;
        //     }
        // }
        // return true;
        // }
      unordered_map<int,int>m;
        
        for(int i : a){
            m[i]++;
        }
        
        for(int i : b){
            
            if(m.count(i)){
                m[i]--;
            }
            else{
                m[i] = 1;
            }
        }
        
        for(auto &it : m){
            if(it.second != 0) return flase;
        }
        
        return true;
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr1, arr2;
        string input1, input2;

        getline(cin, input1); // Read the entire line for the first array elements
        stringstream ss1(input1);
        int number;
        while (ss1 >> number) {
            arr1.push_back(number);
        }

        getline(cin, input2); // Read the entire line for the second array elements
        stringstream ss2(input2);
        while (ss2 >> number) {
            arr2.push_back(number);
        }

        Solution ob;
        cout << (ob.checkEqual(arr1, arr2) ? "true" : "false") << "\n~\n";
    }
    return 0;
}
// } Driver Code Ends
