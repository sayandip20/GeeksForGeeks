//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string colName (long long int s)
    {
        // your code here
        string ans="";
        while(s)
        {
            if(s%26==0)
            {
                ans+='Z';
                s=s/26-1;
            }
            else
            {
                ans+=('A'-1+s%26);
                s/=26;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends