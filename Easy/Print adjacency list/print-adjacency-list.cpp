//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int n, vector<pair<int,int>>arr) {
        // Code here
        unordered_map<int,vector<int>>m;
        
        for(auto i:arr)
        {
            m[i.first].push_back(i.second);
            m[i.second].push_back(i.first);
        }
        
        vector<vector<int>>res;
        
        for(int i=0;i<n;i++)
        {
            vector<int>v(m[i].begin(),m[i].end());
            
            res.push_back(v);
        }
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<pair<int,int>>edges;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u,v});
        }
        Solution obj;
        vector<vector<int>> adj = obj.printGraph(V, edges);
        for(int i=0;i<V;i++)
        {
            sort(adj[i].begin(),adj[i].end());
            for(auto it:adj[i])
                cout<<it<<" ";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends