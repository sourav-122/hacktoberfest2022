

int dd[4][2] = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}
};
 
void bfs(int sx, int sy, vector<vector<int>> &d, vector<vector<int>> &a) {
    int n = d.size();
    int m = d[0].size();
    queue<pair<int, int>> q;
    q.push({sx, sy});
    d[sx][sy] = 1;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (auto [dx, dy] : dd) {
            int tx = x + dx;
            int ty = y + dy;
            if (tx >= 0 && ty >= 0 && tx < n && ty < m && d[tx][ty] == 0 && a[tx][ty] != -1) {
                d[tx][ty] = d[x][y] + 1;
                q.push({tx, ty});
            }
        }
    }
    for (auto &e : d) {
        for (auto &i : e) {
            i--;
        }
    }
}
