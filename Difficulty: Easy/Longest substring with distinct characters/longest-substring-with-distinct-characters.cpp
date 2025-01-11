//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        vector<int>map(26); 
        int ans = 1; 
        int start  = 0; 
        int i  = 0; 
        int n = s.size(); 
        for(; i< n; i++){
            if(map[s[i]-'a']!= 0){
                ans =max(ans,i-start); 
                while(start< n && map[s[i]-'a']!= 0){
                    map[s[start]-'a']--; 
                    start++; 
                }
            }
             map[s[i]-'a']++; 
        }
        ans = max(ans,n-start); 
        return ans ; 
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends