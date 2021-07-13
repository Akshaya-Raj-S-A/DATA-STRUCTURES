#include<iostream>
#include<math.h>
using namespace std;

int main ()
{   int max,shell[100],floor,temporary;
    cout<< "Programmed by AKSHAYA RAJ S A\n";
    cout<<" Enter the number of elements to be sorted :  ";
    cin>> max;
    cout<<"\n  Enter the elements :  ";
    for(int i=0;i<max;i++)
    {
        cin>>shell[i];
    }

    floor=max/2;


    while(floor>=1 && floor<max)
    {
        for (int j = floor; j < max; j++)
        {
            for(int k = j - floor; k >= 0; k = k - floor)
            {
                if (shell[k+floor] >= shell[k])
                {
                    break;
                }
                else
                {
                    temporary = shell[k];
                    shell[k] = shell[k+floor];
                    shell[k+floor] = temporary;
                }
            }
        }
        floor= floor/2;
        if(floor<1)
        {
            break;
        }

    }
cout<<"\n\n ---------------------------- SHELL SORT ---------------------------";


    cout<<"\n  List sorted in ASCENDING ORDER :  ";

    for(int i=0;i<max;i++)
{
    cout<<shell[i]<<"\t";
}

cout<<"\n\n  List sorted in DESCENDING ORDER :  ";
for(int i=max-1;i>=0;i--)
{
    cout<<shell[i]<<"\t";
}
cout<<endl<<endl<<endl;
return 0;
}
