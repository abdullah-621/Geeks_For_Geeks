class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        
        vector<pair<int, int>>merged;
        
        for(int i = 0; i < start.size(); i++)
        {
            merged.push_back({end[i], start[i]});
        }
        
        sort(merged.begin(), merged.end());
        
        int times = 0;
        int last_end = -1;
        
        
        for(int i = 0; i < start.size(); i++)
        {
            int s = merged[i].second;
            int e = merged[i].first;
            
            
            if(s > last_end)
            {
                times++;
                last_end = e;
            }
        }
        
        return times;
    }
};