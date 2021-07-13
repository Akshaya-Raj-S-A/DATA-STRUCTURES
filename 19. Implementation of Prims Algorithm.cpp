#include <bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#define V 500
using namespace std;


bool Edge_validity(int a, int b, vector<bool> val)
{
   if (a == b)
       return false;
   if (val[a] == false && val[b] == false)
        return false;
   else if (val[a] == true && val[b] == true)
        return false;
   return true;
}

void PRIMS_algo(int cost[][V],int edge)
{
    vector<bool> val(edge, false);
    val[0] = true;
    int edge_count = 0, mincost = 0;
    while (edge_count < edge - 1) {

        int min = 100, a = -1, b = -1;
        for (int i = 0; i < edge; i++) {
            for (int j = 0; j < edge; j++) {
                if (cost[i][j] < min) {
                    if (Edge_validity(i, j, val)) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }
        if (a != -1 && b != -1) {
            printf("  Edge %d:(%d, %d) cost: %d \n",
                         edge_count++, a, b, min);
            mincost = mincost + min;
            val[b] = val[a] = true;
        }
    }
    printf("\n\n  Minimum cost= %d \n", mincost);
}


int main()
{

    cout<< "Programmed by AKSHAYA RAJ S A\n";
    int edge;
    cout<<" Enter the number of vertex : ";
    cin>>edge;
    int cost[V][V];
    for(int i=0;i<edge;i++)
    {
    cout<<"\n  Enter the weights of edges from vertex "<<i<<" : ";
    for(int j=0;j<edge;j++)
    {
        cin>>cost[i][j];
    }
    }

    cout<<"\n\n  ------------- PRIM'S ALGORITHM MST -------------\n\n";
    PRIMS_algo(cost,edge);
    cout<<endl<<endl;
    return 0;
}
