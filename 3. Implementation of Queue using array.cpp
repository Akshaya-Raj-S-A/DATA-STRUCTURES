#include<iostream>
int n,i,element;
int A[500];
int max= 500;
int front=-1 ;
int rear = -1;

bool isempty()
{
    if(front==-1 && rear== -1)
    {
      std::cout<<"***Queue is empty***";
    }
    else
    {
       std::cout<<"***Queue is NOT empty***";
    }
}
void enqueue()
{
      if(rear ==(max-1))
    {
        std::cout<<"***Array is full.Element cannot be enqueued*** \n";
    }
    else
    {
        std::cout<< "\nEnter the element to be enqueued : ";
        std::cin>> element ; "\n";
        if (front==-1)
        {
            front= 0;
            rear++;
            A[rear]= element;
            std::cout<<"***Element enqueued successfully*** \n";
        }
        else
        {
            rear++;
            A[rear]= element;
            std::cout<<"***Element enqueued successfully***\n";
        }
    }
}
    void dequeue()
    {
            if(front == - 1 || front > rear)
            {
                std::cout<<"***Queue is empty***\n";
            }
            else
            {

      std::cout<<"\nElement deleted from queue is : "<< A[front]; "\n";
      front++;

            }

        }

    void showfront()

    {

        if(front==-1 && rear==-1)
        {
            std::cout<<"***Queue is empty***\n";
        }
        else
        {
            std::cout<<"\n Element at front : "<<A[front]<< "\n";
        }
    }
    void displayqueue()
    {
         if(front==-1)
        {
            std::cout<<"***Queue is empty***\n";
        }
        else
        {   std::cout<<"\nElements in the queue are: \n";
            for(int i=front;i<= rear;i++)
            {
                std::cout<<A[i]<<"" << "   ";

            }
        }
    }


int main()
{

std::cout<< "Programmed by AKSHAYA RAJ S A\n";
std::cout<<"Enter the range: ";
std::cin>> max ;
while(1)
{
std::cout<<"\n\n1. Check for empty queue\n2.Add an element (Enqueue)\n3.Delete an element (Dequeue)\n4.To show FRONT element\n5.Display the Queue\n6.Exit";
std::cout<<"\n Enter your choice:";
std::cin >> n;
switch(n)
{case 1:
isempty();
break;
case 2:
enqueue();
break;
case 3:
dequeue();
break;
case 4:
showfront();
break;
case 5:
displayqueue();
break;
case 6:
exit(0);
default:
std::cout<<"Invalid option";
}
}
return 0;
}



