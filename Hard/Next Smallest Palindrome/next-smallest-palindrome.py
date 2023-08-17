#User function Template for python3
class Solution:

	def generateNextPalindrome(self,nums, n ) :
	    # code here
        s=(n-1)//2
        f=1 
        for i in range(s,-1,-1):
            l=nums[i]-nums[n-i-1]
            if l:
                f=1 if l<0 else 0
                break;
        if f:                   
            for i in range(s,-1,-1):
                if f==0:  break
                f,nums[i]=divmod(nums[i]+1,10)
            if f:
                nums=[1]+nums
                n=n+1
        for i in range(s+1):
                nums[n-i-1]=nums[i]
        return nums

#{ 
 # Driver Code Starts
#Initial Template for Python 3



# Driver code 
if __name__ == "__main__": 		
    tc=int(input())
    while tc > 0:
        n=int(input())
        num=list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.generateNextPalindrome(num, n)
        for x in ans:
            print(x, end=" ")
        print()
        tc=tc-1
# } Driver Code Ends
