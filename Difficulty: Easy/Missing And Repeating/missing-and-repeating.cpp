//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        unordered_map<int ,int>freq;
        
        for(int i : arr){
            freq[i]++;
        }
        
        vector<int>ans;
        
        for(auto it = freq.begin(); it != freq.end(); it++){
            
            int key = it->first;
            int value = it->second;
            
            if(value > 1) {
            ans.push_back(key); // ✅ repeating number
            break;
        }
        }
        
        for(int i = 1; i <= arr.size(); i++){  // missing number
            
            if(freq.count(i) == 0) {
                ans.push_back(i);
                break;
            }
        }
        return ans;
       
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends