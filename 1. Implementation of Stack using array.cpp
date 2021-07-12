#include<iostream>
#include<conio.h>
#include<stdlib.h>
int max,i,n,x;
int top=-1;
class stack
{
int s[500];
public:
void push();
void pop();
void display();
void topele();
};
void stack::push()
{
int x;
if(top==(max-1))
std::cout<<"Stack is full";
else
{
std::cout<<"enter data:";
std::cin>>x;
top=top+1;
s[top]=x;
}}
void stack::pop()
{
if(top==-1)
std::cout<<"stack  is empty";
else
s[top--]='\0';
std::cout<<" ** Top element deleted **\n";
}
void stack::display()
{
if(top==-1)
std::cout<<"stack is empty"<<"\n";
else
{
std::cout<<"displaying the contents of stack:\n";
for(i=0;i<=top;i++)
std::cout<<s[i]<<"\t";
std::cout<<"\n";
}}
void stack::topele()
{
if(top==-1)
{
std::cout<<"stack is empty"<<"\n";
}
else
{       i=0;
        while(i<=top)
        {
         if(i==top)
          {std::cout<<"The element at the top is: ";
          std::cout<<s[i]<<"\t";
          break;}
         else
          {i++;}
        }
}


        std::cout<<"\n";

}

int main()
{
std::cout<< "Programmed by AKSHAYA RAJ S A \n";
stack operation;
std::cout<<"enter the range:";
std::cin>>max;
while(1)
{
std::cout<<"\n1.push\n2.pop\n3.display\n4.top of the element\n5.exit";
std::cout<<"\n enter ur choice:";
std::cin>>n;
switch(n)
{case 1:
operation.push();
break;
case 2:
operation.pop();
break;
case 3:
operation.display();
break;
case 4:
operation.topele();
break;
case 5:
exit(0);
default:
std::cout<<"Invalid option";
}
}
return 0;
}

