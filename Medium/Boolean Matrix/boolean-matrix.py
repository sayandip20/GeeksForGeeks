#User function Template for python3


#Function to modify the matrix such that if a matrix cell matrix[i][j]
#is 1 then all the cells in its ith row and jth column will become 1.
def booleanMatrix(matrix):
    # code here 
    num_rows, num_cols = len(matrix), len(matrix[0])
    rows_with_ones = set()
    cols_with_ones = set()

    # Identify rows and columns with 1s
    for i in range(num_rows):
        for j in range(num_cols):
            if matrix[i][j] == 1:
                rows_with_ones.add(i)
                cols_with_ones.add(j)

    # Modify matrix based on identified rows and columns
    for i in range(num_rows):
        for j in range(num_cols):
            if matrix[i][j] == 0 and (i in rows_with_ones or j in cols_with_ones):
                matrix[i][j] = 1


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        r,c = map(int, input().strip().split())
        matrix = []
        for i in range(r):
            line = [int(x) for x in input().strip().split()]
            matrix.append(line)
        booleanMatrix(matrix)
        for i in range(r):
            for j in range(c):
                print(matrix[i][j], end=' ')
            print()


# } Driver Code Ends