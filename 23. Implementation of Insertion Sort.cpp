#include<iostream>
using namespace std;
int main ()
{
cout<< "Programmed by AKSHAYA RAJ S A \n";
int sort[100];
int i,j,temporary,max;
cout<<" Enter the number of elements to be sorted : ";
cin>>max;
cout<<endl;
cout<<"  Enter the numbers to be sorted : ";
for(int i=0;i<max;i++)
{
    cin>>sort[i];
}


for(i=1;i<=max-1;i++)
{   j=i;
    while(j>0 && sort[j-1]>sort[j])
    {
        temporary=sort[j];
        sort[j]   = sort[j-1];
        sort[j-1] = temporary;
        j--;
    }
}

cout<<"\n\n -------------------------- INSERTION SORT ------------------------";

cout<<"\n\n Sorted list in ASCENDING ORDER :  ";
for(int i=0;i<max;i++)
{
    cout<<sort[i]<<"\t";
}

cout<<"\n\n Sorted list in DESCENDING ORDER :  ";
for(int i=max-1;i>=0;i--)
{
    cout<<sort[i]<<"\t";
}
cout<<endl<<endl;
return 0;
}



