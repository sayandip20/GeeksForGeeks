#User function Template for python3

class Solution:
    def palindromicPartition(self, string):
        # code here
        n = len(string)
        
        t = [[-1]*(n+1) for _ in range(n+1)]
        
        def isPalindrome(st):
            return st == st[::-1]
            
            
        def solve(i, j):
            if i >= j:
                return 0
                
            if t[i][j] != -1:
                return t[i][j]
                
            if isPalindrome(string[i:j+1]):
                return 0
                
                
            res = float('inf')
            for k in range(i, j):
                if isPalindrome(string[i:k+1]):
                    temp = solve(k+1, j) + 1
                    res = min(res, temp)
                
            t[i][j] = res
            return t[i][j]
            
        return solve(0, n-1)


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range (t):
        string = input()
        
        ob = Solution()
        print(ob.palindromicPartition(string))
# } Driver Code Ends