
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	struct Node *left, *right;
};

struct Node* newNode(int key)
{
	struct Node* temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
};


void inorder(struct Node* temp)
{
	if (!temp)
		return;
	inorder(temp->left);
	cout << temp->key << " ";
	inorder(temp->right);
}


void deletDeepest(struct Node* root,
				struct Node* d_node)
{
	queue<struct Node*> q;
	q.push(root);


	struct Node* temp;
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		if (temp == d_node) {
			temp = NULL;
			delete (d_node);
			return;
		}
		if (temp->right) {
			if (temp->right == d_node) {
				temp->right = NULL;
				delete (d_node);
				return;
			}
			else
				q.push(temp->right);
		}

		if (temp->left) {
			if (temp->left == d_node) {
				temp->left = NULL;
				delete (d_node);
				return;
			}
			else
				q.push(temp->left);
		}
	}
}


Node* deletion(struct Node* root, int key)
{
	if (root == NULL)
		return NULL;

	if (root->left == NULL && root->right == NULL) {
		if (root->key == key)
			return NULL;
		else
			return root;
	}

	queue<struct Node*> q;
	q.push(root);

	struct Node* temp;
	struct Node* key_node = NULL;

	while (!q.empty())
        {
		temp = q.front();
		q.pop();

		if (temp->key == key)
			key_node = temp;

		if (temp->left)
			q.push(temp->left);

		if (temp->right)
			q.push(temp->right);
	}

	if (key_node != NULL) {
		int x = temp->key;
		deletDeepest(root, temp);
		key_node->key = x;
	}
	return root;
}


int main()
{
    cout<< "Programmed by \n****  AKSHAYA RAJ S A  **** \n*** Register No: 1917104 *** \n\n ";

	struct Node* root = newNode(13);
	root->left = newNode(27);
	root->left->left = newNode(90);
	root->left->right = newNode(15);
	root->right = newNode(23);
	root->right->left = newNode(16);
	root->right->right = newNode(31);

	cout << "Inorder traversal before deletion : ";
	inorder(root);

	int key = 90;
	root = deletion(root, key);
    cout<<endl<<endl<<"Element deleted : "<<key<<endl<<endl;


	cout << endl;
	cout << "Inorder traversal after deletion   : ";
	inorder(root);
    cout<<endl<<endl<<endl;

	return 0;

}
