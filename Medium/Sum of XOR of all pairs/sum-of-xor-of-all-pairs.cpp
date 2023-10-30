//{ Driver Code Starts
// An efficient C++ program to compute 
// sum of bitwise OR of all pairs
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
    	long long int sum=0;
    	long long int j=0;
    	while(j<=31){
    	    long long int cnt=0;
    	    for(int i=0; i<n; i++){
    	        int jthbit = int((arr[i] & (1<<j)) > 0);
    	        cnt += jthbit;
    	    }
    	    long long int val = (pow(2, j) * (n-cnt)*(cnt)); 
    	    sum += val;
    	    j++;
    	}
    	return sum;
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	 int n ;
	 cin>>n;
	 int arr[n+1];
	 for( int i=0;i<n;i++)
	    cin>>arr[i];
	 Solution ob;
	 cout<<ob.sumXOR(arr, n)<<endl;
	}	
	return 0;
}

// } Driver Code Ends