//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.io.*;
import java.lang.*;

class Geeks
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            int n =sc.nextInt();
            int arr[] = new int[n];
            
            for(int i = 0; i < n; i++)
             arr[i] = sc.nextInt();
             
           System.out.println(new Solution().majorityElement(arr, n)); 
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution
{
    static int majorityElement(int a[], int size)
    {
        // your code here
        Map<Integer,Integer> m = new HashMap<>();
        for(int i : a){
            if(m.containsKey(i)){
                m.put(i,m.get(i)+1);
            }else{
                m.put(i,1);
            }
        }
        int n = size / 2;
        for(Map.Entry<Integer,Integer> e : m.entrySet()){
            if(e.getValue() > n){
                return e.getKey();
            }
        }
        return -1;
    }
}