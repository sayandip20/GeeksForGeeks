//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        // Your code here
        vector<int> x[26] , y[26];
        vector<vector<int>> p, q;
        for(int i = 0; i<str1.size() ; i++){
             x[str1[i]-'a'].push_back(i);
        }
        for(int i = 0; i<str2.size() ; i++){
             y[str2[i]-'a'].push_back(i);
        }
        for(int i = 0 ; i<26 ; i++){
            if(x[i].size()){
                p.push_back(x[i]);
            }
            if(y[i].size()){
                q.push_back(y[i]);
            }
        }
        sort(p.begin(),p.end());
        sort(q.begin(),q.end());
        return (p == q);
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends