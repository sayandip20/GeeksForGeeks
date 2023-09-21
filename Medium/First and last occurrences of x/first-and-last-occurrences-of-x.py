#User function Template for python3


class Solution:
    def find(self, arr, n, x):
        
        # code here
        if x in arr:
            one = arr.index(x)
            for i,j in enumerate(arr):
                if j == x:
                    two = i
            return [one,two]
        return [-1,-1]


#{ 
 # Driver Code Starts
t=int(input())
for _ in range(0,t):
    l=list(map(int,input().split()))
    n=l[0]
    x=l[1]
    arr=list(map(int,input().split()))
    ob = Solution()
    ans=ob.find(arr,n,x)
    print(*ans)
# } Driver Code Ends