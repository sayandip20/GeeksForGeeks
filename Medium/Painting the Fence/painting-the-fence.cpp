//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long countWays(int n, int k){
        // code here
        int mod = 1e9 + 7;
        long long same = 0, diff = k;
    
        for (int i = 2; i <= n; i++) {
            long long prevSame = same;
            same = diff;
            diff = (prevSame + diff) * (k - 1) % mod;
        }
    
        return (same + diff) % mod;
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends