#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* link;
};
struct Node* front= NULL;
struct Node* rear= NULL;
struct Node* temporary;

bool isempty()
{
    if(front== NULL && rear== NULL)
    {
        cout<<"\n ***Queue is empty(underflow)***";
    }
    else
    {
        cout<<"\n *** Queue is NOT empty ***";
    }
}
void enqueue()
{
    int element;
   cout<<"\n Insert the element in queue : ";
   cin>>element;
   if (rear == NULL)
   {
      rear = (struct Node *)malloc(sizeof(struct Node));
      rear->link = NULL;
      rear->data = element;
      front = rear;
      cout<<"*** Element inserted successfully ***";
   }
   else
    {
      temporary=(struct Node *)malloc(sizeof(struct Node));
      rear->link = temporary;
      temporary->data = element;
      temporary->link= NULL;
      rear = temporary;
      cout<<"*** Element inserted successfully ***";
   }
}
void showfront()
{
    if(front==NULL)
    {
        cout<<"\n*** Queue is empty ***\n";
    }
    else
    {
        cout<<"\n The element at the top is:  ";
        cout<< front->data;
    }
}
void dequeue() {
   temporary = front;
   if (front == NULL) {
      cout<<"\n *** Queue is empty ***"<<endl;
      return;
   }
   else
   if (temporary->link != NULL) {
      temporary = temporary->link;
      cout<<"\n Element deleted from queue is : "<<front->data<<endl;
      free(front);
      front = temporary;

   } else {
      cout<<"\n Element deleted from queue is : "<<front->data<<endl;
      free(front);
      front = NULL;
      rear = NULL;
   }
}
void displayqueue() {
   temporary = front;
   if ((front == NULL) && (rear == NULL)) {
      cout<<"***Queue is empty***"<<endl;
      return;
   }
   cout<<"\nQueue elements are:  ";
   while (temporary != NULL)
    {
      cout<<temporary->data<<" ";
      cout<<"    ";
      temporary = temporary->link;
   }
   cout<<endl;
}
int main()
 {
int n;
cout<< "Programmed by AKSHAYA RAJ S A \n";

while(1)
{
        cout<<"\n\n1. Check for empty queue\n2.Add an element (Enqueue)\n3.Delete an element (Dequeue)\n4.To show FRONT element\n5.Display the Queue\n6.Exit";
cout<<"\n Enter your choice:";
cin >> n;
      switch (n)
      {
         case 1:
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
         break;
         default: cout<<"Your choice is invalid"<<endl;
      }
   }
   return 0;
}

