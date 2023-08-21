//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > arr, int n)
    {
        // code here 
        int maxx = 0;
        int r[n] = {0}, c[n] = {0};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                r[i] += arr[i][j];
                c[i] += arr[j][i];
                maxx = max(maxx, max(r[i], c[i]));
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += maxx- r[i];
            ans += maxx- c[i];
        }
        return ans/2;
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends
