#include<stdio.h>
int main()
{
int n,e,i,j;
printf("enter number of vertices:");
scanf("%d",&n);

int adj[20][20]={0},indeg[20]={0};
printf("enter number of edges:");
scanf("%d",&e);
printf("enter edges(u v):\n");
for(i=1;i<=e;i++){
int u,v;
scanf("%d%d",&u,&v);
adj[u][v]=1;
indeg[v]++;
}
printf("topological order:\n");
for(int count=1;count<=n;count++)
{
    for(i=1;i<=n;i++)
    {
        if(indeg[i]==0)
        break;
    }
    if(indeg[i]==n)
    {
        printf("the graph has a cycle!");
        return 0;
    }
    printf("%d",i);
    indeg[i]=-1;
for(j=1;j<=n;j++)
{
    if(adj[i][j]==1)
    indeg[j]--;

}
}
return 0;
}


