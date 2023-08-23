//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
       //Your code here
       int n1 = s1.size();
       int n2 = s2.size();
       int n3 = n1 + n2 ;
       string ans;
       for(int i=0;i<n3;i++) ans+="0";
       for(int i=n2 - 1;i>=(int)(s2[0]=='-');i--){
           int num1 = s2[i] - '0';
           int carry = 0;
           for(int j=n1-1;j>=(int)(s1[0]=='-');j--){
               int num2 = s1[j] - '0';
               int prod = num1*num2;
               int total = prod%10 + ans[i+j+1] - '0' + carry;
               ans[i+j+1] = total%10 + '0';
               carry = prod/10 + total/10;
           }
           ans[i + (int)(s1[0]=='-')] +=  carry;
       }
       string ans1;
       if((s1[0] == '-') ^ (s2[0] == '-')) ans1+='-';
       int i=0;
        while(i<n1+n2 && ans[i] == '0'){
            i++;
        }
        for(;i<n3;i++){
            ans1 += ans[i];
        }
    return ans1;
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends