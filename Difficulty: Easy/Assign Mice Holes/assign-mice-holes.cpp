class Solution {
  public:
    int assignHole(vector<int>& mices, vector<int>& holes) {
        // code here
        sort(mices.begin(), mices.end());
        sort(holes.begin(), holes.end());
        
        vector<int>result;
        
        for(int i = 0; i < holes.size(); i++)
        {
            int times = abs(holes[i] - mices[i]);
            result.push_back(times);
        }
        
        priority_queue<int>pq(result.begin(), result.end());
        
        return pq.top();
    }
};