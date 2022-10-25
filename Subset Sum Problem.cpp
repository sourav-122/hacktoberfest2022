#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
using namespace std;



int SubsetSumProblem::solve(vector<int> &A, int B) {
    
    int n=A.size();
    
    int dp[102][100001];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<B+1;j++)
        {
            if(i==0)
            dp[i][j]=0;
            if(j==0)
            dp[i][j]=1;
        }
    }
    
    
     
    
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<B+1;j++)
        {
            if(A[i-1]<=j)
            {
                dp[i][j]=(dp[i-1][j-A[i-1]])||(dp[i-1][j]);
            }
            else 
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    
    return dp[n][B];
    
    
}
