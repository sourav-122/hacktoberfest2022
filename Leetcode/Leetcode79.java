class Solution 
{
    public boolean exist = false;
    public boolean exist(char[][] board, String word)
    {
        int n = board.length;
        int m = board[0].length;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(board[i][j]==word.charAt(0))
                {
                    dfs(i, j, board, n, m, word, new boolean[n][m], 0, "");
                    if(exist)
                        return true;
                }
            }
        }
        return false;
    }
    
    public void dfs(int i, int j, char[][] board, int n, int m, 
                    String word, boolean[][] vis, int k, String cur)
    {
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || board[i][j] != word.charAt(k))
            return;
        vis[i][j] = true;
        if((cur + board[i][j]).equals(word))
            exist = true;
        if(exist)
            return;
        dfs(i+1, j, board, n, m, word, vis, k+1, cur+board[i][j]);
        dfs(i-1, j, board, n, m, word, vis, k+1, cur+board[i][j]);
        dfs(i, j+1, board, n, m, word, vis, k+1, cur+board[i][j]);
        dfs(i, j-1, board, n, m, word, vis, k+1, cur+board[i][j]);
        vis[i][j] = false;
    }
}
