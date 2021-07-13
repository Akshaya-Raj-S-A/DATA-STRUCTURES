
#include <bits/stdc++.h>
using namespace std;

#define V 500
int parent[V];
int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void union1(int i, int j)
{
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void kruskalMST(int cost[][V], int edge)
{
    int mincost = 0;
    for (int i = 0; i < edge; i++)
        parent[i] = i;
      int edge_count = 0;
    while (edge_count < edge - 1) {
        int min = INT_MAX, a = -1, b = -1;
        for (int i = 0; i < edge; i++) {
            for (int j = 0; j < edge; j++) {
                if (find(i) != find(j) && cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        union1(a, b);
        printf("  Edge %d:(%d, %d) cost:%d \n",
               edge_count++, a, b, min);
        mincost += min;
    }
    printf("\n\n  Minimum cost= %d \n", mincost);
}


int main()
{
    cout<< "Programmed by AKSHAYA RAJ S A\n";
    int edge;
    int cost[V][V];
    cout<<"  Enter the total number of vertices : ";
    cin>>edge;
    for(int i=0;i<edge;i++)
    {   cout<<"\n  Enter the weights of edges from vertex "<<i<<" : ";
        for(int j=0;j<edge;j++)
        {
           cin>>cost[i][j];
        }
    }
    cout<<"\n\n  --------------- KRUSKAL'S ALGORITHM MST ---------------\n\n";
    kruskalMST(cost, edge);
    return 0;
}

