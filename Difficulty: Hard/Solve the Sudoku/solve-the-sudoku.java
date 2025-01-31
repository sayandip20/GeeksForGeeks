//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = 9;
            int matrix[][] = new int[n][n];
            // String st[] = read.readLine().trim().split("\\s+");
            int k = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) matrix[i][j] = sc.nextInt();
            }
            Solution ob = new Solution();
            ob.solveSudoku(matrix);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) System.out.print(matrix[i][j] + " ");
                System.out.println();
            }
            System.out.println("~");
        }
    }
}

// } Driver Code Ends
class Solution 
{
    static void solveSudoku(int[][] mat) 
    {
        solve(mat);
    }
    static boolean isValid(int[][] mat, int row, int col, int num) 
    {
        for (int i = 0; i < 9; i++) 
        {
            if (mat[row][i] == num || mat[i][col] == num) 
            {
                return false;
            }
        }
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = 0; i < 3; i++) 
        {
            for (int j = 0; j < 3; j++) 
            {
                if (mat[startRow + i][startCol + j] == num) 
                {
                    return false;
                }
            }
        }
        return true;
    }
    static boolean solve(int[][] mat) 
    {
        for (int row = 0; row < 9; row++) 
        {
            for (int col = 0; col < 9; col++) 
            {
                if (mat[row][col] == 0) 
                {
                    for (int num = 1; num <= 9; num++) 
                    {
                        if (isValid(mat, row, col, num)) 
                        {
                            mat[row][col] = num;

                            if (solve(mat)) 
                            {
                                return true;
                            }
                            mat[row][col] = 0;
                        }
                    }
                    return false;
                }
            }
        }
        return true; 
    }
}