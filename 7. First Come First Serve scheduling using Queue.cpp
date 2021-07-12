#include<iostream>
#include<string>
using namespace std;

int main()

{

    cout<< "Programmed by AKSHAYA RAJ S A\n ";

    int n,burst_time[20],waiting_time[20],turn_around[20],avg_waiting=0,avg_turnaround=0;
    int i,j;
    cout<<"Enter total number of processes:";
    cin>>n;


    for(i=0;i<n;i++)
    {
        cout<<"Enter Burst Time for Process["<<i+1<<"]:";
        cin>>burst_time[i];
    }

    waiting_time[0]=0;
    for(i=1;i<n;i++)
    {
        waiting_time[i]=0;
        for(j=0;j<i;j++)
            waiting_time[i]+=burst_time[j];
    }

    cout<<"\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";


    for(i=0;i<n;i++)
    {
        turn_around[i]=burst_time[i]+waiting_time[i];
        avg_waiting+=waiting_time[i];
        avg_turnaround+=turn_around[i];
        cout<<"\nProcess["<<i+1<<"]"<<"\t"<<burst_time[i]<<"\t\t"<<waiting_time[i]<<"\t\t"<<turn_around[i];
    }

    avg_waiting/=i;
    avg_turnaround/=i;
    cout<<"\n\nAverage Waiting Time:"<<avg_waiting;
    cout<<"\n" ;
    cout<<"\nAverage Turnaround Time:"<<avg_turnaround;
    cout<<"\n\n" ;
    return 0;
}
