#include<iostream>
#include<stddef.h>
#include<stdio.h>

using namespace std;
int x;

struct entry
{
    int key;
    int value;
};

struct ht_entry
{

    int probe;
    struct entry *data;

};
struct ht_entry *arr;
int size = 0;
int maximum = 500;

int hashcode(int key)
{
    return (key % maximum);
}
void insert(int key, int value)
{
    int index = hashcode(key);
    int i = index;
    struct entry *new_entry = (struct entry*) malloc(sizeof(struct entry));
    new_entry->key = key;
    new_entry->value = value;
    while (arr[i].probe == 1)
    {

	if (arr[i].data->key == key)
        {
		cout<<"\n Key already exists. Do you need to update the value?(If YES - 1) :  ";
		cin>>x;
		if(x ==1)
        {
            arr[i].data->value = value;
        }
        else
            {
                cout<<" ** TRY INSERTING WITH SOMEOTHER KEY VALUE ** ";
            }
		return;

	}

	i = (i + 1) % maximum;
	if (i == index)
        {
		cout<<"\n ** HASH TABLE IS FULL... INSERION FAILED **\n";
		return;
	}

    }

    arr[i].probe = 1;
    arr[i].data = new_entry;
    size++;
    cout<<"\n ** Key "<<key<<" has been inserted **\n";

}

void deletion (int key)
{
    int index = hashcode(key);
    int  i = index;
    while (arr[i].probe != 0)
    {

	if (arr[i].probe == 1  &&  arr[i].data->key == key )
        {
		arr[i].probe =  2;
		arr[i].data = NULL;
		size--;
		cout<<"\n ** Key "<<key<<" has been removed **\n";
		return;

	}
	i = (i + 1) % maximum;
	if (i == index)
    {
		break;
	}

    }
    cout<<"\n ** KEY DOES NOT  EXIST ** \n";

}
void display()
{
    int i;
    for (i = 0; i < maximum; i++)
    {
	struct entry *current = (struct entry*) arr[i].data;

	if (current == NULL)
        {
	    cout<<"\n ** INDEX ["<<i<<"] HAS NO ELEMENTS **\n";
	}
	else
        {
	    cout<<"\n ** INDEX ["<<i<<"] : KEY = "<< current->key <<" ;  VALUE = "<< current->value<<"\n";
	}
    }

}

int hash_size()
{
    return size;
}

int main()
{
    std::cout<< "Programmed by AKSHAYA RAJ S A\n ";
	int choice, key, value, n, c;
	arr = (struct ht_entry*) malloc(maximum * sizeof (struct ht_entry));
	cout<<"Enter the maximum size of the HASH TABLE : ";
	cin>>maximum;
	for (int i = 0; i < maximum; i++)
    {
	arr[i].probe = 0;
	arr[i].data = NULL;
    }
	do
        {
		cout<<"\n\n 1. Insertion in the Hashtable"
                              "\n 2. Deletion from the Hashtable"
                              "\n 3. Size of Hashtable"
                              "\n 4. Display Hashtable"
                              "\n 5. EXIT";
        cout<< "\n\n Enter your choice :  ";
		std::cin >> choice;
		switch(choice){
		case 1:

		      cout<<" Enter key and value to be inserted :";
		      cin>>key>>value;
		      insert(key, value);
		      break;
		case 2:
		      cout<<" Enter the key to delete : ";
		      cin>>key;
		      deletion (key);
		      break;
		case 3:
		      n = hash_size();
		      cout<<"\n SIZE OF THE HASH TABLE : "<< n;
		      break;
		case 4:
		      display();
		      break;
        case 5:
              exit(0);
		default:
		       cout<<" ** Enter a valid option **\n";
		}

	}while(choice!=5);


     return 0;

}
