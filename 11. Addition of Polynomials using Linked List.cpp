#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
struct Node{
   int coeff;
   int pow;
   struct Node *next;
};
void create_node(int i, struct Node **temp)
{  int x,y;
   struct Node *r, *z;
   z = *temp;
   cout<<"Enter coefficient of term["<<i<<"] : ";
       cin>>x;
       cout<<"Enter power of term["<<i<<"] : ";
       cin>>y;
   if(z == NULL){
      r =(struct Node*)malloc(sizeof(struct Node));
      r->coeff = x;
      r->pow = y;
      *temp = r;
      r->next = (struct Node*)malloc(sizeof(struct Node));
      r = r->next;
      r->next = NULL;
   } else {
      r->coeff = x;
      r->pow = y;
      r->next = (struct Node*)malloc(sizeof(struct Node));
      r = r->next;
      r->next = NULL;
   }
}
void polyadd(struct Node *p1, struct Node *p2, struct Node *result){
   while(p1->next && p2->next){
      if(p1->pow > p2->pow){
         result->pow = p1->pow;
         result->coeff = p1->coeff;
         p1 = p1->next;
      }
      else if(p1->pow < p2->pow){
         result->pow = p2->pow;
         result->coeff = p2->coeff;
         p2 = p2->next;
      } else {
         result->pow = p1->pow;
         result->coeff = p1->coeff+p2->coeff;
         p1 = p1->next;
         p2 = p2->next;
      }
      result->next = (struct Node *)malloc(sizeof(struct Node));
      result = result->next;
      result->next = NULL;
   }
   while(p1->next || p2->next){
      if(p1->next){
         result->pow = p1->pow;
         result->coeff = p1->coeff;
         p1 = p1->next;
      }
      if(p2->next){
         result->pow = p2->pow;
         result->coeff = p2->coeff;
         p2 = p2->next;
      }
      result->next = (struct Node *)malloc(sizeof(struct Node));
      result = result->next;
      result->next = NULL;
   }
}
void printpoly(struct Node *node){
   while(node->next != NULL)
    {
      printf("%dx^%d", node->coeff, node->pow);
      node = node->next;
      if(node->next != NULL)
         printf(" + ");
   }
}
int main(){
    int i,n1,n2;
   struct Node *p1 = NULL, *p2 = NULL, *result = NULL;
   cout<< "Programmed by AKSHAYA RAJ S A\n";
   cout<<"Enter number of terms in first polynomial: ";
   cin >>n1;
   cout<<endl;
    i=1;
   while(i<=n1)
   {
       create_node(i,&p1);
       cout<<endl;
       i++;
   }
    cout<<"*************************************************\n\n";
   cout<<"Enter number of terms in second polynomial: ";
   cin>>n2;
   cout<<endl;
   i=1;
   while(i<=n2)
   {
       create_node(i,&p2);
       cout<<endl;
       i++;
   }
cout<<"*************************************************\n\n";

   printf("First polynomial: ");
   printpoly(p1);
   printf("\nSecond polynomial: ");
   printpoly(p2);

cout<<"\n\n*************************************************\n\n";

   result = (struct Node *)malloc(sizeof(struct Node));
   polyadd(p1, p2, result);
   printf(" Resultant polynomial after addition : ");
   printpoly(result);
   cout<<endl<<endl;
   return 0;
}
