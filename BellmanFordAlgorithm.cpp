#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <climits>
#include <set>
#include <stack>
#include <algorithm>
using namespace std;

int bellmonFord(int n,int m,int src,int dest,vector<vector<int>> edges){

  vector<int> dist(n+1,1e9);
  dist[src]=0;
  //n-1 times
  for(int i=1;i<=n;i++){
    //traverse on edge list
    for(int j=0;j<m;j++){
      int u=edges[j][0];
      int v=edges[j][1];
      int wt=edges[j][2];

      if(dist[u]!=1e9 && (dist[u]+wt<dist[v])){
        dist[v]=dist[u]+wt;
      }
    }
  }
  //check for negative cycle
  bool flag=0;
  for(int j=0;j<m;j++){
      int u=edges[j][0];
      int v=edges[j][1];
      int wt=edges[j][2];

      if(dist[u]!=1e9 && (dist[u]+wt<dist[v])){
        flag=1;
      }
  }
  if(flag==0){
    return dist[dest];
  }
 return -1; 
}

int main() {

  vector<vector<int>>edges={{1,2,2},{2,3,-1},{1,3,2}};
  int src=1;
  int dest=3;
  int n=3;
  int m=3;
  int ans=bellmonFord(n,m,src,dest,edges);
  cout<<"The shortest path from 1 to 3 is "<<endl;
  cout<<ans;

  
  return 0;
}
