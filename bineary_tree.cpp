/*
	author of this code is rohit sharma
*/
#include<bits/stdc++.h>

using namespace std;

class Tree
{
public:
	int data;
	Tree * left;
	Tree * right;
	Tree(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};
Tree * buildTree() {
	int data;
	cin >> data;
	if (data == -1) {
		return NULL;
	}
	Tree * n = new Tree(data);
	n->right = buildTree();
	n->left = buildTree();
	return n;
}
void preOrder(Tree * root) {
	if(root == NULL){
		return;
	}
	cout<<root->data<<" ,";
	preOrder(root->left);
	preOrder(root->right);
}
void inOrder(Tree * root){
	if(root == NULL){
		return;
	}
	inOrder(root->left);
	cout<<root->data<<" ,";
	inOrder(root->right);
}
void postOrder(Tree * root){
	if(root == NULL){
		return;
	}
	postOrder(root->right);
	cout<<root->data<<" ,";
	postOrder(root->left);
}
int main() {
	Tree*root = NULL;
	root = buildTree();
	// preOrder(root);
	inOrder(root);
	return 0;
}	