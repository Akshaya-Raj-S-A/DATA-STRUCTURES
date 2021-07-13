#include <bits/stdc++.h>

using namespace std;

struct Node {

    int coeff, power;

    Node* next;
};


Node* addnode(Node* start, int coeff, int power)
{


    Node* newnode = new Node;

    newnode->coeff = coeff;

    newnode->power = power;

    newnode->next = NULL;





    if (start == NULL)

        return newnode;




    Node* ptr = start;

    while (ptr->next != NULL)

        ptr = ptr->next;

    ptr->next = newnode;



    return start;
}

void printList(struct Node* ptr)
{
    while (ptr->next != NULL) {
        cout << ptr->coeff << "x^" << ptr->power << " + ";

        ptr = ptr->next;
    }
    cout << ptr->coeff <<"x^" << ptr->power << "\n";
}
void removeDuplicates(Node* start)
{

    Node *ptr1, *ptr2, *dup;

    ptr1 = start;


    while (ptr1 != NULL && ptr1->next != NULL) {

        ptr2 = ptr1;


        while (ptr2->next != NULL) {

            if (ptr1->power == ptr2->next->power) {

                ptr1->coeff = ptr1->coeff + ptr2->next->coeff;

                dup = ptr2->next;

                ptr2->next = ptr2->next->next;

                delete (dup);

            }

            else

                ptr2 = ptr2->next;

        }

        ptr1 = ptr1->next;

    }
}
Node* multiply(Node* poly1, Node* poly2,

               Node* poly3)
{

    Node *ptr1, *ptr2;

    ptr1 = poly1;

    ptr2 = poly2;

    while (ptr1 != NULL) {

        while (ptr2 != NULL) {

            int coeff, power;


            coeff = ptr1->coeff * ptr2->coeff;

            power = ptr1->power + ptr2->power;

            poly3 = addnode(poly3, coeff, power);

            ptr2 = ptr2->next;

        }

        ptr2 = poly2;
        ptr1 = ptr1->next;

    }

    removeDuplicates(poly3);

    return poly3;
}

int main()
{


    int n1,n2,x,y;
    Node *poly1 = NULL, *poly2 = NULL, *poly3 = NULL;
   cout<< "Programmed by AKSHAYA RAJ S A\n ";
   cout<<"Enter number of terms in first polynomial: ";
   cin >>n1;
   cout<<endl;
   for(int i=0;i<n1;i++)
   {
       cout<<"Enter coefficient of term["<<i+1<<"] : ";
       cin>>x;
       cout<<"Enter power of term["<<i+1<<"] : ";
       cin>>y;
       poly1 = addnode(poly1, x, y);
       cout<<endl;

   }
   cout<<"\n\n*************************************************\n\n";
   cout<<"Enter number of terms in first polynomial: ";
   cin >>n2;
   cout<<endl;
   for(int i=0;i<n2;i++)
   {
       cout<<"Enter coefficient of term["<<i+1<<"] : ";
       cin>>x;
       cout<<"Enter power of term["<<i+1<<"] : ";
       cin>>y;
       poly2 = addnode(poly2, x, y);
       cout<<endl;
   }
    cout<<"\n\n*************************************************\n\n";

    cout<<"The polynomials are, \n";
    cout << "First Polynomial: ";

    printList(poly1);

    cout << "Second Polynomial: ";

    printList(poly2);
    cout<<"\n\n*************************************************\n\n";

    poly3 = multiply(poly1, poly2, poly3);

    cout << "Resultant Polynomial after multiplication: ";

    printList(poly3);

    cout<<endl;

    return 0;
}
