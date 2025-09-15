class Solution {
  public:
  
    void MinCandy(vector<int>prices,int k, vector<int>& ans)
    {
        sort(prices.begin(), prices.end());
        
        int i = 0, j = prices.size() - 1;
        
        int MinPrice = 0;
        
        while(i <= j)
        {
            MinPrice += prices[i];
            i++;
            j -= k;
        }
        
        ans.push_back(MinPrice);
    }
    
    void MaxCandy(vector<int>prices,int k, vector<int>& ans)
    {
        sort(prices.begin(), prices.end(), greater<int>());
        
        int i = 0, j = prices.size() - 1;
        
        int MaxPrice = 0;
        
        while(i <= j)
        {
            MaxPrice += prices[i];
            i++;
            j -= k;
        }
        
        ans.push_back(MaxPrice);
    }
  
  
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        vector<int>ans;
        
        MinCandy(prices, k , ans);
        MaxCandy(prices, k , ans);
        
    
        return ans;
    }
};