class Solution
{
    private : 
    bool isHamiltonianPathExists(vector<int> graph[],vector<int> &visited,int cnt,int node,int n)
    {
        visited[node] = 1;
        for(auto &adjNode : graph[node])
        {
            if(!visited[adjNode])
            {
                if(isHamiltonianPathExists(graph,visited,cnt+1,adjNode,n))
                   return true;
            }
        }
        if(cnt == n) return true;
        visited[node] = 0;
        return false;
    }
    public:
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        vector<int> graph[N+1];
        for(int i=0; i<M; i++)
        { 
           graph[Edges[i][0]].push_back(Edges[i][1]);
           graph[Edges[i][1]].push_back(Edges[i][0]);
        } 
        vector<int> visited(N+1,0);
        for(int i=1; i<=N; i++)
        {  
            if(visited[i] == 0)
            {
                if(isHamiltonianPathExists(graph,visited,1,i,N)) 
                   return true;
            }
        }
        return false;  
    }
};
