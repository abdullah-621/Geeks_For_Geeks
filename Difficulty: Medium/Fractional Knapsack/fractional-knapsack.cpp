class Solution {
  public:
  
    static bool comp(pair<int,int>a, pair<int,int>b)
    {
        double r1 = (double)a.first / a.second;
        double r2 = (double)b.first / b.second;
        
        return r1 > r2;
    }
  
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<pair<int,int>>arr;
        
        for(int i = 0; i < val.size(); i++)
        {
            arr.push_back({val[i], wt[i]});
        }
        
        
        sort(arr.begin(), arr.end(), comp);
        
        double profit = 0.0;
        int i = 0;
        
        while(capacity > 0 && i < val.size())
        {
            if(capacity >= arr[i].second)
            {
                profit += arr[i].first;
                capacity -= arr[i].second;
            }
            
            else
            {
                double temp = arr[i].second;
                temp = (arr[i].first / temp )  * capacity;
                profit += temp;
                capacity = 0;
            }
            
            i++;
        }
        
        return profit;
    }
};
























