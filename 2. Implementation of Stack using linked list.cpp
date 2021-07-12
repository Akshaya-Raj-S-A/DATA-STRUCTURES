#include<iostream>
using namespace std;

class node {
  public:
int key=0;
int data=0;
node * next=NULL;


};

class linklist
{
    public:
    node * head;

  linklist()
  {
    head = NULL;
  }
  linklist(node * n)
  {
    head = n;
  }

  node * isnode(int k)
   {
    node * temporary = NULL;

    node * ptr = head;
    while (ptr != NULL)
        {
      if (ptr -> key == k)
       {
        temporary = ptr;
      }
      ptr = ptr -> next;

    }
    return temporary;
  }

  void addnode(node * n) {
    if (isnode(n -> key) != NULL) {
      cout << "Node is existing already"<<endl;
    } else {
      if (head == NULL) {
        head = n;
        cout << "Node added successfully" << endl;
      } else {
        node * ptr = head;
        while (ptr -> next != NULL) {
          ptr = ptr -> next;
        }
        ptr -> next = n;
        cout << "Node added successfully" << endl;
      }
    }

  }
  void insert(int k, node * n) {
    node * ptr = isnode(k);
    if (ptr == NULL) {
      cout << "Node does not exist" << endl;
    } else {
      if (isnode(n -> key) != NULL) {
        cout << "Node is existing already"<<endl;
      } else {
        n -> next = ptr -> next;
        ptr -> next = n;
        cout << "Node is inserted successfully" << endl;
      }
    }
  }

  void deletenode(int k) {
    if (head == NULL) {
      cout << "List is Empty." << endl;
    } else if (head != NULL) {
      if (head -> key == k) {
        head = head -> next;
        cout << "NOde" << k << " deleted successfully" << endl;
      } else {
        node * temp = NULL;
        node * before = head;
        node * current = head -> next;
        while (current != NULL) {
          if (current -> key == k) {
            temp = current;
            current = NULL;
          } else {
            before = before -> next;
            current = current -> next;
          }
        }
        if (temp != NULL) {
          before -> next = temp -> next;
          cout <<  "NOde" << k << " deleted successfully"  << endl;
        } else {
          cout <<  "NOde" << k << " does not exist"  << endl;
        }
      }
    }
  }
  void print() {
    if (head == NULL) {
      cout << "Linked list is empty";
    } else {
      cout << endl << "Singly Linked List elements : ";
      node * temporary = head;

      while (temporary != NULL) {
        cout << "(" << temporary -> key << "," << temporary -> data << ")\v ";
        temporary = temporary -> next;
      }
    }
  }
};

int main() {

  linklist s;
  int option;
  int key1, k1, data1;
  std::cout<< "Programmed by AKSHAYA RAJ S A \n";
  while (1)
{
    cout << "\n Enter your choice" << endl;
    cout << "1. Add a Node" << endl;
    cout << "2. Insert" << endl;
    cout << "3. Delete a Node" << endl;
    cout << "4. Print" << endl;
    cout << "5. Exit" << endl;

    cin >> option;
    node * n1 = new node();
    switch (option) {
    case 0:
      break;
    case 1:
      cout << "\nEnter position & data of the Node to be Added" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      s.addnode(n1);
      break;
    case 2:
      cout << "\nEnter position of existing Node after which you want to Insert this New node: " << endl;
      cin >> k1;
      cout << "Enter position & data of the New Node first: " << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      s.insert(k1, n1);
      break;
    case 3:
      cout << "\nEnter position of the Node to be deleted: " << endl;
      cin >> k1;
      s.deletenode(k1);
      break;
    case 4:
      s.print();
      break;
    case 5:
        exit(0);
    default:
        cout<<"Enter a valid option";
    }

  }
  return 0;
}


























