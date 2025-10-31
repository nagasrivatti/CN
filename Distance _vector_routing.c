#include<stdio.h>
#define INF 999
#define MAX 20
struct RoutingTable{
        int dist[MAX];
        int nextHop[MAX];
};
void main(){
        int n; int cost[MAX][MAX];
        char nodes[MAX][20];
        struct RoutingTable rt[MAX];
        printf("Enter number of nodes (hosts/roters): ");
        scanf("%d",&n);
        printf("Enter node names (e.g., H1, H2, ...):\n");
        for(int i=0;i<n;i++){
                printf("Node %d: ",i+1);
                scanf("%s",nodes[i]);
        }
        printf("\nEnter adjacency matrix (delay cost, INF=999, 0 for self):\n");
        for(int i=0;i<n;i++){
                for(int j=0;j<n;j++)
                        scanf("%d",&cost[i][j]);
        }
        for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                        rt[i].dist[j]=cost[i][j];
                        if(cost[i][j]!=INF && i!=j)
                                rt[i].nextHop[j]=j;
                        else
                                rt[i].nextHop[j]=-1;
                }
        }
        int updated;
        do{
                updated=0;
                for(int i=0;i<n;i++){
                        for(int j=0;j<n;j++){
                                for(int k=0;k<n;k++){
                                        if(rt[i].dist[j]> cost[i][k] +rt[k].dist[j]){
                                                rt[i].dist[j]=cost[i][k]+rt[k].dist[j];
                                                updated=1;
                                        }
                                }
                        }
                }
        }while(updated);
        for(int i=0;i<n;i++){
                printf("\nRouting Table for Node %s:\n",nodes[i]);
                printf("Destination\tNextHop\t\tCost\n");
                for(int j=0;j<n;j++){
                        if(i==j) continue;
                        printf("%s\t\t",nodes[j]);
                        if(rt[i].nextHop[j]!=-1)
                                printf("%s\t\t",nodes[rt[i].nextHop[j]]);
                        else
                                printf("-\t\t");
                        if(rt[i].dist[j]==INF)
                                printf("INF\n");
                        else
                                printf("%d\n",rt[i].dist[j]);
                }
                o/p:
                        Enter number of nodes (hosts/roters): 4 
Enter node names (e.g., H1, H2, ...): 
Node 1: h1 
Node 2: h2 
Node 3: h3 
Node 4: h4 
Enter adjacency matrix (delay cost, INF=999, 0 for self): 0 
12 
9 
4 
12 
0 
1 
999 
9 
1 
0 
2 
4 
999 
2 
0 
Routing Table for Node h1: 
Destination NextHop Cost
h2 h2 7 
h3 h3 6 
h4 h4 4 
Routing Table for Node h2: Destination NextHop Cost h1 h1 7 
h3 h3 1 
h4 - 3 
Routing Table for Node h3: Destination NextHop Cost h1 h1 6 
h2 h2 1 
h4 h4 2 
Routing Table for Node h4: Destination NextHop Cost h1 h1 4 
h2 - 3 
h3 h3 2

        }
}
o/p:
        
