class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> d) {
        // code here
         if(grid[d.first][d.second]==0)
        return -1;

        int n=grid.size();
        int m=grid[0].size();

        int dp[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][j]=-1;
            }
        }

        queue<pair<int,int>> q;

        dp[source.first][source.second]=0;

        q.push(source);

        int ans=-1;

        while(!q.empty())
        {
            pair<int,int> t=q.front();
            q.pop();
            int i=t.first;
            int j=t.second;


            if(i-1>=0&&dp[i-1][j]==-1&&grid[i-1][j]==1){
                dp[i-1][j]=dp[i][j]+1;
                 q.push({i-1,j});
            }

             if(j-1>=0&&dp[i][j-1]==-1&&grid[i][j-1]==1){
                dp[i][j-1]=dp[i][j]+1;
                 q.push({i,j-1});
            }

             if(i+1<n&&dp[i+1][j]==-1&&grid[i+1][j]==1){
                dp[i+1][j]=dp[i][j]+1;
                 q.push({i+1,j});
            }

             if(j+1<m&&dp[i][j+1]==-1&&grid[i][j+1]==1){
                dp[i][j+1]=dp[i][j]+1;
                 q.push({i,j+1});
            }

      }


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==d.first&&j==d.second){
                ans=dp[i][j];
                }
            }
        }

    return ans;

    }
};
