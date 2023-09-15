//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    int mod = 1000000007;
    long long countWays(int n)
    {
        // your code here
        if(n<=1) return 1;
        if(n == 2) return n;
        long long f = 1,s = 1, t = 2;
        for(int i = 3 ;i<= n;i++){
            long long dp = (f+s+t)%mod;
            f = s, s = t, t = dp;
        }
        return t;
    }


};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends