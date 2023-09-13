#User function Template for python3
class Solution:
    def perfectSum(self, numbers, length, targetSum):
        # Initialize a dynamic programming array with 0-based indexing
        dp = [1] + [0] * targetSum  # dp[i] represents the count of perfect sums that add up to 'i'

        MOD = 10**9 + 7  # A constant for modulo arithmetic

        # Iterate through the numbers in the input array
        for number in numbers:
            # Iterate through the possible sums in reverse order
            for currentSum in range(targetSum, number - 1, -1):
                # Calculate the count of perfect sums for the current sum
                # by adding the count of perfect sums for (currentSum - number)
                dp[currentSum] = (dp[currentSum] + dp[currentSum - number]) % MOD
        
        # Return the count of perfect sums for the target sum
        return dp[targetSum]


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		n,sum = input().split()
		n,sum = int(n),int(sum)
		arr = [int(x) for x in input().split()]
		ob = Solution()
		ans = ob.perfectSum(arr,n,sum)
		print(ans)

# } Driver Code Ends