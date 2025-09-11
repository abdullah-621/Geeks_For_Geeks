// class Solution {
//   public:
    
//     void DFS(int node, vector<vector<int>>& adj,  vector<bool>&visited, stack<int>&s)
//     {
//         visited[node] = true;
        
//         for(int i = 0; i < adj[node].size(); i++)
//         {
//             if(!visited[adj[node][i]])
//             {
//                 DFS(adj[node][i], adj, visited, s);
//             }
//         }
//         s.push(node);
//         // push at last node into stack
//     }
  
  
//     vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
//         vector<vector<int>> adj(V);
        
//         for(int i = 0; i < edges.size(); i++)
//         {
//             int u = edges[i][0];
//             int v = edges[i][1];
//             adj[u].push_back(v);
            
//         }
        
//         // code here
//         vector<bool>visited(V, false);
//         stack<int>s;
        
//         for(int i = 0; i < visited.size(); i++)
//         {
//             if(!visited[i])
//             {
//                 DFS(i, adj, visited, s);
//             }
//         }
        
//         vector<int>ans;
        
//         while(!s.empty())
//         {
//             ans.push_back(s.top());
//             s.pop();
//         }
        
//         return ans;
//     }
// };




// *************************** using bfs ******************************



class Solution {
  public:
  
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) 
    {
        
        // Step 1: adjacency list বানানো
        vector<vector<int>>adj(V);
        
        for(int i = 0 ; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
        }
        
        
        
        // Step 2: indegree বের করা
        
        vector<int>Indegree(V, 0);
    
        for(int i = 0; i < edges.size(); i++)
        {
            int d = edges[i][1];
            Indegree[d]++;
        }
        
        
        // Step 3: queue তে 0 indegree node রাখা
        
        queue<int>q;
        
        for(int i = 0; i < V; i++)
        {
            if(Indegree[i] == 0)
            {
                q.push(i);
            }
        }
        
        
        // Step 4: process করা
        
        vector<int>ans;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(int i = 0; i < adj[node].size(); i++)
            {
                int nbr = adj[node][i];
                Indegree[nbr]--;
                
                if(Indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
                
            }
            
        }
    
        return ans;
    
    }
};