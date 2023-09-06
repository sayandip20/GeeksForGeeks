//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        vector<int> steps(100000,1e8);
        queue<int> q;
        q.push(start);
        int currSteps = 0;
        while(!q.empty()){
            int Qsize = q.size();
            for(int i=0;i<Qsize;i++){
                int num = q.front();
                q.pop();
                if(num == end) return currSteps;
                for(int choice : arr){
                    int newNum = (num * choice) % 100000;
                    if(1 + currSteps < steps[newNum]){
                        q.push(newNum);
                        steps[newNum] = 1 + currSteps;
                    }
                }
            }
            currSteps++;
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends