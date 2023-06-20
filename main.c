#include <stdio.h>
#include<limits.h>
int main()
{
    int n;
    printf("Enter the no of nodes:");
    scanf("%d",&n);
    int count=0,i,j,graph[n][n],mincost=0,min,dist[n],visit[n],a,b;
    printf("Enter the adjacency matrix\n");
    for(i=0;i<n;i++){
        dist[i]=INT_MAX;
        visit[i]=0;
        for(j=0;j<n;j++)
            scanf("%d",&graph[i][j]);
    }
    visit[0]=1;
    dist[0]=0;
    printf("Vertex\t Distance from source\n");
    while(count<n-1){
        for(i=0;i<n && visit[i]==1;i++)/* visit[i]==1 means only from the visited node can continue the traversal source and
            two or more nodes can be visited from the same visited node if the weight of the path is much more smaller
            and this for loop is valid for visit[i]=1 so that's why we used visit[i]==1 inside the for loop condition
            instead of using if condition after the for loop*/
                for(j=0;j<n;j++)
                   if(visit[j]==0 && graph[i][j] && dist[i]+graph[i][j]<=dist[j] && min>dist[i]+graph[i][j])/*visit[j]==0 is used so that to avoid the loop or
                   the previous minimum weight of the visited node will not be used again
                    i.e, if the current most min weight is from 1->2=3 so min=3 and it will be visited so visit[2]=1
                     and the next most min weight is from say 2->4=5 or 1->3=5, which is greater than 3 and their visit[4] and visit[3] is 0 and visit[2] is 1
                     so the if condition for visit[2] will not be fulfilled 
                    **min is used to choose the shortest path to unvisited node which can be 
                    travel at the moment from the source directly or indirectly through other visited nodes and min
                    value will update the most min weight after checking every possible weights available at the moment*/
                        {
                        dist[j]=dist[i]+graph[i][j];
                        min=dist[j];
                        b=j;
                        }
        mincost+=min;
        count++;
        printf("%d\t\t%d\n",b+1,min);
        visit[b]=1;
        min=INT_MAX;//we are giving min as INT_MAX so that min>dist[i]+graph[i][j] can be used
    }
    printf("The total min cost:%d",mincost);
    return 0;
}
