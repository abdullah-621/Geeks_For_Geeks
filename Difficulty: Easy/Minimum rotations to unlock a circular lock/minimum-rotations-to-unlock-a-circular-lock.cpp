// User function Template for C++

class Solution {
  public:
    int rotationCount(long long R, long long D) {
        // code here
        
        int ans = 0;
        
        while(R != 0 || D != 0)
        {
            int r = R % 10;
            int d = D % 10;
            
            int diff = abs(r - d);
            
            diff = min(diff , 10 - diff);
            
            ans += diff;
            
            R = R / 10;
            D = D / 10;
        }
        
        return ans;
        
    }
};