#include <iostream>
#include <vector>


using namespace std;

int main()
{
    cout<< "Programmed by AKSHAYA RAJ S A\n ";

	int i,n,time,remain,temps=0,quantum_time;

	int waiting_time=0,turn_around=0;

	cout<<"Enter the total number of process=";
	cin>>n;

	remain=n;

	vector<int>arrival_time(n);
	vector<int>burst_time(n);
	vector<int>rt(n);
	for(i=0;i<n;i++)
	{
        cout<<"Enter the Arrival time, Burst time for process["<<i+1 <<"]"<<endl;
		cin>>arrival_time[i];
		cin>>burst_time[i];
		rt[i]=burst_time[i];
	}

	cout<<"*Enter the value of Time Quantum:";
	cin>>quantum_time;

	cout<<"\n\nProcess\t\t:Turnaround Time:Waiting Time\n\n";
	for(time=0,i=0;remain!=0;)
	{
		if(rt[i]<=quantum_time && rt[i]>0)
		{
			time += rt[i];
			rt[i]=0;
			temps=1;
		}

		else if(rt[i]>0)
		{
			rt[i] -= quantum_time;

			time += quantum_time;

		}

		if(rt[i]==0 && temps==1)
		{
			remain--;
			printf("Process[%d]\t:\t%d\t:\t%d\n",i+1,time-arrival_time[i],time-arrival_time[i]-burst_time[i]);
			cout<<endl;

			waiting_time += time-arrival_time[i]-burst_time[i];
			turn_around += time-arrival_time[i];
			temps=0;
		}

		if(i == n-1)
			i=0;
		else if(arrival_time[i+1] <= time)
			i++;
		else
			i=0;
	}

	cout<<"Average waiting time "<<waiting_time*1.0/n<<endl;
	cout<<"Average turn around time "<<turn_around*1.0/n<<endl;;

	return 0;
}
