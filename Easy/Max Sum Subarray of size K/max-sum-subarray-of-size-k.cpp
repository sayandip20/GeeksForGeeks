//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        int a=0;
        int b =a+K;
        long sum=0;
        long p=INT_MIN;
        for(int i=a;i<b;i++){
            sum+=Arr[i];
        }
        while(b<=N){
            p= max(p,sum);
            sum-=Arr[a];
            sum+=Arr[b];
            a++;
            b++;
        }
       return p;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends