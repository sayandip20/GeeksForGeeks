//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int size;
    vector<int>diagup,diagdown,horizontal;
    
    void helper(int col, vector<int> &ds, vector<vector<int>> &ans) {
        if (col >= size) {
            ans.push_back(ds);
            return;
        }
    
        for (int r = 0; r < size; r++) {
            if (!horizontal[r] && !diagdown[r + col] && !diagup[r - col + (size - 1)]) {
                horizontal[r] = 1;
                diagdown[r + col] = 1;
                diagup[r - col + (size - 1)] = 1;
                ds.push_back(r + 1);
                helper(col + 1, ds, ans);
                ds.pop_back();
                horizontal[r] = 0;
                diagdown[r + col] = 0;
                diagup[r - col + (size - 1)] = 0;
            }
        }
    }
    
    vector<vector<int>> nQueen(int n) {
        // code here
        size = n;
        vector<vector<int>> ans;
        vector<int> ds;
        diagup.resize(2 * n - 1, 0);
        diagdown.resize(2 * n - 1, 0);
        horizontal.resize(n, 0);
        helper(0, ds, ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends