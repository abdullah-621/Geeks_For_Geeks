class Solution {
  public:
    
    void DFS(int node, vector<vector<int>>& adj,  vector<bool>&visited, stack<int>&s)
    {
        visited[node] = true;
        
        for(int i = 0; i < adj[node].size(); i++)
        {
            if(!visited[adj[node][i]])
            {
                DFS(adj[node][i], adj, visited, s);
            }
        }
        s.push(node);
        // push at last node into stack
    }
  
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(V);
        
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            
        }
        
        // code here
        vector<bool>visited(V, false);
        stack<int>s;
        
        for(int i = 0; i < visited.size(); i++)
        {
            if(!visited[i])
            {
                DFS(i, adj, visited, s);
            }
        }
        
        vector<int>ans;
        
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        
        return ans;
    }
};