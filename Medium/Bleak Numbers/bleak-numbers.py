#User function Template for python3

class Solution:
	def countSetBits(self,n):
        count=0
        while n>0:
            if n%2==1:
                count+=1
            n=n//2
        return count
    
    def is_bleak(self, n):
        i=0
        while True:
            t=2**i
            if n<t:
                break
            i+=1
        for x in range(n-i,n):
            if x+self.countSetBits(x)==n:
                return 0
        return 1


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		n = int(input())
		ob = Solution();
		ans = ob.is_bleak(n)
		print(ans)

# } Driver Code Ends