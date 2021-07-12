
#include <iostream>
#include <queue>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;
};


Node* CreateNode(int data)
{
    Node* newNode = new Node();
    if (!newNode) {
        cout << "** Error in memory allocation **\n";
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}



Node* InsertNode(Node* root, int data)
{
    if (root == NULL) {
        root = CreateNode(data);
        return root;
    }


    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->left != NULL)
            q.push(temp->left);
        else {
            temp->left = CreateNode(data);
            return root;
        }

        if (temp->right != NULL)
            q.push(temp->right);
        else {
            temp->right = CreateNode(data);
            return root;
        }
    }
}


void inorder(Node* temp)
{
    if (temp == NULL)
        return;

    inorder(temp->left);
    cout << temp->data << ' ';
    inorder(temp->right);
}

int main()
{   cout<< "Programmed by AKSHAYA RAJ S A\n ";

    Node* root = CreateNode(35);
    root->left = CreateNode(9);
    root->left->left = CreateNode(13);
    root->right = CreateNode(78);
    root->right->left = CreateNode(43);


    cout << "Inorder traversal before insertion: ";
    inorder(root);
    cout << endl<<endl;

    int key = 100;
    root = InsertNode(root, key);
    cout<<"Element inserted : "<<key<<endl<<endl;

    cout << "Inorder traversal after insertion  : ";
    inorder(root);
    cout << endl<<endl<<endl;

    return 0;
}
