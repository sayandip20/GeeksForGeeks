//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            String S = br.readLine().trim();
            Solution obj = new Solution();
            ArrayList<String> ans = obj.findPermutation(S);
            Collections.sort(ans);
            for (int i = 0; i < ans.size(); i++) {
                out.print(ans.get(i) + " ");
            }
            out.println();

            out.println("~");
        }
        out.close();
    }
}

// } Driver Code Ends

class Solution {
    Set<String> ans;
    public ArrayList<String> findPermutation(String s) {
        ans = new HashSet<>();
        solve(0,s.length(),s.toCharArray());
        return new ArrayList<>(ans);
    }
    void solve(int i,int n,char a[]){
        if(i==n){
            ans.add(new String(a));
            return;
        }
        
        for(int j=i;j<n;j++){
            swap(i,j,a);
            solve(i+1,n,a);
            swap(i,j,a);
        }
    }
    void swap(int i,int j,char a[]){
        char temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}