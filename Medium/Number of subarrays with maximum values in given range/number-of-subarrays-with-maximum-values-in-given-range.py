#User function Template for python3

class Solution:
    def countSubarrays(self, a,n,L,R): 
        # Complete the function
        ls=[i for i in range(n) if a[i]>R]
        ans,j,c=[0]*3
        for i in range(n):
            if j==len(ls) or i<ls[j]:
                if a[i]>=L:
                    if j==len(ls):
                        ans+=(c+1)*(n-i)
                    else:
                        ans+=(c+1)*(ls[j]-i)
                    c=0
                else:
                    c+=1
            else:
                c=0
                j+=1
        return ans


#{ 
 # Driver Code Starts
#Initial Template for Python 3



for _ in range(0,int(input())):
    n,l,r = map(int, input().strip().split())
    arr = list(map(int,input().strip().split()))
    ob = Solution()
    v = ob.countSubarrays(arr, n, l, r)
    print(v)
    
# } Driver Code Ends