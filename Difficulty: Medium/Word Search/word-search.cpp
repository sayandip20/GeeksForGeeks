//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    bool dfs(int x, int y, int idx, vector<vector<char>> &mat, vector<vector<bool>> &vis, string &w, int &m, int &n) {
        if(idx == w.size()) return true;
        if(x>=m || y>=n || x<0 || y<0 || vis[x][y] || mat[x][y]!=w[idx]) return false;
        
        vis[x][y] = 1;
        
        if(dfs(x, y+1, idx+1, mat, vis, w, m, n) || dfs(x+1, y, idx+1, mat, vis, w, m, n) || dfs(x, y-1, idx+1, mat, vis, w, m, n) || dfs(x-1, y, idx+1, mat, vis, w, m, n)) {
            return true;
        }
        
        vis[x][y] = 0;
        return false;
    }
  public:
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<bool>> vis (m, vector<bool> (n, 0));
        
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(mat[i][j] == word[0]) {
                    if(dfs(i, j, 0, mat, vis, word, m, n)) return true;
                }
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends