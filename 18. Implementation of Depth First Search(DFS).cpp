#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
int cost[100][100],i,j,k,n,STACK[100],top,v,visit[100],visited[100];
int main()
{
    cout<< "Programmed by AKSHAYA RAJ S A\n";
    int m;
    cout <<" Enter no of vertices :  ";
    cin >> n;
    cout <<endl<<" Enter no of edges :  ";
    cin >> m;
    cout <<endl<<"\n  EDGES \n";
    for(k=1; k<=m; k++)
    {
        cin >> i>> j;
        cost[i][j]=1;
    }
    cout <<"\n  Enter initial vertex to traverse from :  ";
    cin >>v;
    cout <<"\n  DFS ORDER OF VISITED VERTICES :  ";
    cout << v <<" ";
    visited[v]=1;
    k=1;
    while(k<n)
    {
        for(j=n; j>=1; j--)
            if(cost[v][j]!=0 && visited[j]!=1 && visit[j]!=1)
            {
                visit[j]=1;
                STACK[top]=j;
                top++;
            }
        v=STACK[--top];
        cout<<v << " ";
        k++;
        visit[v]=0;
        visited[v]=1;
    }
    cout<<endl<<endl;
    return 0;
}
