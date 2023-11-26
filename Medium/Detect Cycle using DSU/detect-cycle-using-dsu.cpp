//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find root of a node.
    int find_set(int v, vector<int>&parent)
    {
        //calling function recursively to get parent node.
        if(v != parent[v])
        v = find_set(parent[v], parent);
        return v;
    }
    
    //Function to merge two nodes a and b.
    void unionn(int x, int y, vector<int>&parent, vector<int>&rank)
    {
        x = find_set(x, parent);
        y = find_set(y, parent);
        if(rank[x] < rank[y])
            swap(x, y);
        parent[y] = x;
        rank[x] += rank[y];
    }
    
    //Function to detect cycle using DSU in an undirected graph.
    int detectCycle(int V, vector<int>adj[])
    {
        vector<int>parent(V);
        vector<int>rank(V,0);
        
        for(int i = 0; i < V; i++){
            parent[i] = i;
            rank[i] = 1;
        }
        
        map<pair<int,int>,int>mp;
        for(int u = 0; u < V; u++)
        {
            //iterating through all edges of graph, finding subset of
            //both vertices of every edge, if both subsets are
            //same, then there is cycle in graph.
            for(auto v: adj[u])
            {
                if(mp.find({u,v}) != mp.end() or mp.find({v,u}) != mp.end())
                    continue;
                mp[{v,u}] = 1;
                int x = find_set(u, parent);
                int y = find_set(v, parent);
                if(x == y)
                {
                    //returning 1 if there is a cycle.
                    return 1;
                }
                unionn(u, v, parent, rank);
            }
        }
        return 0;
    }
}; 

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends