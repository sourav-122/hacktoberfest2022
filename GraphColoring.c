//Graph Coloring algorithm using backtracking in c
#include<stdio.h>
int G[10][10],m,edges,color_tab[10],v1,v2,i,j,n,a,b;
void Gen_Col_Value(int,int);
void Gr_coloring(int,int);
int main()
{
 printf("\nEnter the number of nodes & edges\n");
 scanf("%d%d",&n,&edges);
 m=n-1;
 printf("\nEnter the edges of the graph\n\n");
 for (i=1;i<=edges; i++)
 {
  printf("Enter value of x,y\n");
  scanf("%d%d",&v1,&v2);
   G[v1][v2] = G[v2][v1] = 1;
   printf("\n");
 }
 Gr_coloring(1,n);
 printf("\n The Vertices To be Coloured As...\n");
  for(i=1;i<=n;i++)
    printf("\n V%d:=%d",i,color_tab[i]);
 return 0;
}
void Gen_Col_Value(int k,int n)
{
 while(1)
 {
  a=color_tab[k]+1;
  b=m+1;
  color_tab[k] = a%b; 
  if(color_tab[k]==0) return;    
  for(j=1;j<=n;j++)
  {    
   if(G[k][j] && color_tab[k]==color_tab[j])
     break;
  }
  if(j==n+1) return; 
   }
}
void Gr_coloring(int k,int n)
{
  Gen_Col_Value(k,n);
  if(color_tab[k]==0) return;   
  if(k==n)  return;     
  else Gr_coloring(k+1,n);  
}
/*
output:-
Enter the number of nodes & edges
4
5
Enter the edges of the graph
Enter value of x,y
0
1
Enter value of x,y
1
2
Enter value of x,y
1
3
Enter value of x,y
2
3
Enter value of x,y
3
0
 The Vertices To be Coloured As...
 V1:=1
 V2:=2
 V3:=3
 V4:=1
 
 
 Time Complexity: O(V^2 + E) in worst case.
*/
