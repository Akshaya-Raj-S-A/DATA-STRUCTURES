#include<iostream>

using namespace std;

class Node {
  public:
    int key;
  int data;
  Node * next;
  Node * previous;

  Node() {
    key = 0;
    data = 0;
    next = NULL;
    previous = NULL;
  }
  Node(int k, int d) {
    key = k;
    data = d;
  }
};

class DoublyLinkedList {

  public:
    Node * head;

  DoublyLinkedList() {
    head = NULL;
  }
  DoublyLinkedList(Node * n) {
    head = n;
  }


  Node * nodeExists(int k) {
    Node * temp = NULL;
    Node * ptr = head;

    while (ptr != NULL) {
      if (ptr -> key == k) {
        temp = ptr;
      }
      ptr = ptr -> next;
    }

    return temp;
  }


  void appendNode(Node * n) {
    if (nodeExists(n -> key) != NULL) {
      cout << "Node Already exists with key value : " << n -> key << ". Append another node with different Key value" << endl;
    } else {
      if (head == NULL) {
        head = n;
        cout << "Node Appended as Head Node" << endl;
      } else {
        Node * ptr = head;
        while (ptr -> next != NULL) {
          ptr = ptr -> next;
        }
        ptr -> next = n;
        n -> previous = ptr;
        cout << "Node Appended" << endl;
      }
    }
  }

  void prependNode(Node * n) {
    if (nodeExists(n -> key) != NULL) {
      cout << "Node Already exists with key value : " << n -> key << ". Append another node with different Key value" << endl;
    } else {
      if (head == NULL) {
        head = n;
        cout << "Node Prepended as Head Node" << endl;
      } else {
        head -> previous = n;
        n -> next = head;
        head = n;
        cout << "Node Prepended" << endl;
      }

    }
  }

  void insertNodeAfter(int k, Node * n) {
    Node * ptr = nodeExists(k);
    if (ptr == NULL) {
      cout << "No node exists with key value: " << k << endl;
    } else {
      if (nodeExists(n -> key) != NULL) {
        cout << "Node Already exists with key value : " << n -> key << ". Append another node with different Key value" << endl;
      } else {
        Node * nextNode = ptr -> next;
        if (nextNode == NULL) {
          ptr -> next = n;
          n -> previous = ptr;
          cout << "Node Inserted at the END" << endl;
        }

        else {
          n -> next = nextNode;
          nextNode -> previous = n;
          n -> previous = ptr;
          ptr -> next = n;

          cout << "Node Inserted in Between" << endl;

        }

      }
    }
  }

  void deleteNodeByKey(int k) {
    Node * ptr = nodeExists(k);
    if (ptr == NULL) {
      cout << "No node exists with key value: " << k << endl;
    } else {

      if (head -> key == k) {
        head = head -> next;
        cout << "Node UNLINKED with keys value : " << k << endl;
      } else {
        Node * nextNode = ptr -> next;
        Node * prevNode = ptr -> previous;
        if (nextNode == NULL) {

          prevNode -> next = NULL;
          cout << "Node Deleted at the END" << endl;
        }

        else {
          prevNode -> next = nextNode;
          nextNode -> previous = prevNode;
          cout << "Node Deleted in Between" << endl;

        }
      }
    }
  }

  void updateNodeByKey(int k, int d) {

    Node * ptr = nodeExists(k);
    if (ptr != NULL) {
      ptr -> data = d;
      cout << "Node Data Updated Successfully" << endl;
    } else {
      cout << "Node Doesn't exist with key value : " << k << endl;
    }

  }

  void printList() {
    if (head == NULL) {
      cout << "No Nodes in Doubly Linked List";
    } else {
      cout << endl << "Doubly Linked List Values : ";
      Node * temp = head;

      while (temp != NULL) {
        cout << "(" << temp -> key << "," << temp -> data << ") <--> ";
        temp = temp -> next;
      }
    }

  }

};

int main() {

  DoublyLinkedList obj;
  int option;
  int key1, k1, data1;
  cout<< "Programmed by AKSHAYA RAJ S A\n ";

  do {
    cout << "\nSelect the operation to be performed.\n";
    cout << "1. Append a Node" << endl;
    cout << "2. Prepend a Node" << endl;
    cout << "3. Insert Node After" << endl;
    cout << "4. Delete Node By Key" << endl;
    cout << "5. Update Data of Node By Key" << endl;
    cout << "6. Print List" << endl;
    cout << "7. Clear Screen" << endl;
    cout << "8. Exit" << endl << endl;


    cin >> option;
    Node * n1 = new Node();
    //Node n1;

    switch (option) {
    case 1:
      cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      obj.appendNode(n1);
      //cout<<n1.key<<" = "<<n1.data<<endl;
      break;

    case 2:
      cout << "Enter key & data of the Node to be Prepended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      obj.prependNode(n1);
      break;

    case 3:
      cout << "Enter key of existing Node after which New node is to be inserted: " << endl;
      cin >> k1;
      cout << "Enter key & data of the New Node first: " << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;

      obj.insertNodeAfter(k1, n1);
      break;

    case 4:

      cout << "Enter key of the Node to be deleted: " << endl;
      cin >> k1;
      obj.deleteNodeByKey(k1);

      break;
    case 5:
      cout << "Enter key & NEW data to be updated" << endl;
      cin >> key1;
      cin >> data1;
      obj.updateNodeByKey(key1, data1);

      break;
    case 6:
      obj.printList();

      break;
    case 7:
      system("cls");
      break;
    case 8:
        exit(0);
    default:
      cout << "Enter a valid option" << endl;
    }

  } while (option != 0);

  return 0;
}
