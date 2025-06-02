class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        // Your code here
        unordered_map<int,int>freq;
        
        for(int i : a)
        {
            freq[i]++;
        }
        
        for(int i : b)
        {
            auto it = freq.find(i);
            if(it == freq.end() || freq[i] == 0) return false;
            
            freq[i]--;
        }
        
        return true;
    }
};