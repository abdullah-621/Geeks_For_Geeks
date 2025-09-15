class Solution {
  public:
    int findMin(int n) {
        
        vector<int>currency = {10,5,2,1};
        
        int notes = 0, i = 0;
        
        
        while(n)
        {
            int coins = n / currency[i];
            
            notes += coins;
            
            n = n - (currency[i] * coins);
            
            i++;
        }
        
        return notes;
    }
};