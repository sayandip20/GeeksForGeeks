//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    void dfs(int i, int j, int n, int m, vector<vector<char>>&mat, vector<vector<int>>&vis){
        if (i<0 || i>=n || j<0 || j>=m || vis[i][j] || mat[i][j]=='X') return;
        vis[i][j]=1;
        
        dfs(i-1, j, n, m, mat, vis);
        dfs(i+1, j, n, m, mat, vis);
        dfs(i, j-1, n, m, mat, vis);
        dfs(i, j+1, n, m, mat, vis);
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for (int i=0; i<n; i++)
            dfs(i, 0, n, m, mat, vis),
            dfs(i, m-1, n, m, mat, vis);
            
        for (int j=0; j<m; j++)
            dfs(0, j, n, m, mat, vis),
            dfs(n-1, j, n, m, mat, vis);
        
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                if (mat[i][j]=='O' && vis[i][j]==0)
                    mat[i][j]='X';
                    
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends