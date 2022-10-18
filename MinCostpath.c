/*
Given a cost matrix cost[][] and a position (m, n) in cost[][], write a function that returns cost of minimum cost path to reach (m, n) from (0, 0). 
Each cell of the matrix represents a cost to traverse through that cell. 
The total cost of a path to reach (m, n) is the sum of all the costs on that path (including both source and destination). 
You can only traverse down, right and diagonally lower cells from a given cell, i.e., from a given cell (i, j), cells (i+1, j), (i, j+1), and (i+1, j+1) can be traversed. You may assume that all costs are positive integers.
*/

/* A Naive recursive implementation of MCP(Minimum Cost Path) problem */
#include<stdio.h>
#include<limits.h>
#define R 3
#define C 3

int min(int x, int y, int z);

/* Returns cost of minimum cost path from (0,0) to (m, n) in mat[R][C]*/
int minCost(int cost[R][C], int m, int n)
{
if (n < 0 || m < 0)
	return INT_MAX;
else if (m == 0 && n == 0)
	return cost[m][n];
else
	return cost[m][n] + min( minCost(cost, m-1, n-1),
							minCost(cost, m-1, n),
							minCost(cost, m, n-1) );
}

/* A utility function that returns minimum of 3 integers */
int min(int x, int y, int z)
{
if (x < y)
	return (x < z)? x : z;
else
	return (y < z)? y : z;
}

/* Driver program to test above functions */
int main()
{
int cost[R][C] = { {1, 2, 3},
					{4, 8, 2},
					{1, 5, 3} };
printf(" %d ", minCost(cost, 2, 2));
return 0;
}


// Output
// 3
// Time Complexity O( 3^(m*n))
