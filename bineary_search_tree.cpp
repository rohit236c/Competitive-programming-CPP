/*
	author of this code is rohit sharma
*/
#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node * right;
	Node * left;
	Node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};
void buildLevelTree(Node * &root) {
	int data;
	cin >> data;
	root = new Node(data);
	queue<Node *>q;
	q.push(root);
	while (!q.empty()) {
		Node * n = q.front();
		q.pop();
		int d1, d2;
		cin >> d1 >> d2;
		if (d1 != -1) {
			n -> left = new Node(d1);
			q.push(n->left);
		}
		if (d2 != -1) {
			n -> right = new Node(d2);
			q.push(n->right);
		}
	}
}
class balBst {
public:
	int height;
	bool balance;
};
balBst isBalanced(Node * root) {
	balBst b;

	if (root == NULL) {
		b.height = 0;
		b.balance = true;
		return b;
	}
	balBst leftSide = isBalanced(root->left);
	balBst rightSide = isBalanced(root->right);

	int diff = abs(leftSide.height - rightSide.height);

	if (diff <= 1 && leftSide.balance && rightSide.balance) {
		b.balance = true;
	}
	else {
		b.balance = false;
	}

	b.height = max(leftSide.height, rightSide.height) + 1;

	return b;
}
Node * insert(Node*&root, int data) {
	if (root == NULL) return new Node(data);


	if (root->data > data) {
		root->left = insert(root->left, data);
	}
	else {
		root->right = insert(root->right, data);
	}

	return root;
}
void printPreorder(Node*root) {
	if (root == NULL) return;

	cout << root->data << " ";
	printPreorder(root->left);
	printPreorder(root->right);
}
void printByLevelQueue(Node * root) {
	queue<Node *>q;
	q.push(root);
	q.push(NULL);
	while (!q.empty()) {
		Node* front = q.front();
		cout << front->data << " ";
		q.pop();

		if (front->left != NULL) {
			q.push(front->left);
		}
		if (front->right != NULL)
		{
			q.push(front->right);
		}
		if (q.front() == NULL) {
			q.pop();
			if (!q.empty())
				q.push(NULL);

			cout << endl;
		}
	}
}
Node*buildBalanceTree(int * arr, Node*root, int s, int e) {
	if (s > e) {
		return NULL;
	}
	int mid = (s + e) / 2;

	root = new Node(arr[mid]);

	root->left = buildBalanceTree(arr, root->left, s, mid - 1);
	root->right = buildBalanceTree(arr, root->right, mid + 1, e);

	return root;
}

Node* buildBalanceTree(int * arr, Node*&root, int n) {
	int s = 0;
	int e =  n;
	cout << "size = " << e << '\n';

	return buildBalanceTree(arr, root, s, e - 1);
}

bool is_Bst(Node*root, int max, int min) {
	if (root == NULL) {
		return true;
	}

	bool leftRoot  = is_Bst(root->left, root->data-1, min);
	bool rightRoot = is_Bst(root->right, max, root->data+1);
	if (root->data <= max && root->data >= min && leftRoot && rightRoot) {
		return true;
	}
	else {
		return false;
	}
}
Node* search (Node*root,int key){
	if(root == NULL)
		return NULL;

	if(root->data == key){
		return root;
	}
	if(key < root->data){
		return search(root->left,key);
	}
	else{
		return search(root->right,key);
	}
}
Node* printAncestors(Node*root, multimap<Node*, int>map, int key1,int key2) {
	Node* k1 = search(root,key1);
	Node* k2 = search(root,key2);
	int ans1;
	Node* ans;	

	std::pair <std::multimap<Node*, int>::iterator, std::multimap<Node*, int>::iterator> ret;
	std::pair <std::multimap<Node*, int>::iterator, std::multimap<Node*, int>::iterator> ret2;
	ret = map.equal_range(k1);
	ret2 = map.equal_range(k2);
	for (std::multimap<Node*, int>::iterator i = ret.first; i != ret.second; ++i)
	{
		for (std::multimap<Node*, int>::iterator j = ret2.first; j != ret2.second; ++j)
		{
			if(i->second == j->second){
				ans1 = j->second ;
			}

		}
		break;
	}
	ans = search(root,ans1);
	return ans;
}
void test(Node*root , multimap<Node*, int>&map){
	cout<<root->left->data<<"     ";
	std::pair <std::multimap<Node*, int>::iterator, std::multimap<Node*, int>::iterator> ret;
		ret = map.equal_range(root);
	for (std::multimap<Node*, int>::iterator j = ret.first; j != ret.second; ++j)
		{
			cout<<j->second<<" ";

		}
}
void printAncestor(Node * root, multimap<Node*, int>&map, Node*prev) {
	if (root == NULL) {
		return ;
	}
	if (prev != NULL) {
		// cout<<"root "<<root->data<<" prev "<<prev->data<<" loop-> ";
		map.insert(pair<Node*, int>(root, prev->data));

		std::pair <std::multimap<Node*, int>::iterator, std::multimap<Node*, int>::iterator> ret;
		ret = map.equal_range(prev);
		for (std::multimap<Node*, int>::iterator i = ret.first; i != ret.second; ++i)
		{
			if (i->second != -1 || i->second != prev->data){
				cout <<i ->second<<" ";
				map.insert(pair<Node*, int>(root, i->second));
			}
			
		}
		map.insert(pair<Node*, int>(root, root->data));
		cout<<endl;
	}
	else {
		// cout<<"root "<<root->data<<" prev "<<endl;
		map.insert(pair<Node*, int>(root, -1));
		map.insert(pair<Node*, int>(root, root->data));
	}
	 printAncestor(root->left, map, root);
	 printAncestor(root->right, map, root);
}
Node* printAncestor(Node* root,int v1, int v2) {
	multimap<Node*, int>map;
	printAncestor(root, map, NULL);
	test(root,map);
	return printAncestors(root, map, v1,v2);
}
class LinkedList{
public:
	Node*head;
	Node*tail;
};

LinkedList flattenList(Node*&root){
	LinkedList ll;
	if(root == NULL){
		ll.head = NULL;
		ll.tail = NULL;
		return ll;
	}
	if(root->left == NULL && root->right == NULL){
		ll.head = ll.tail = root;
	}
	else if(root->left != NULL && root->right == NULL){
			LinkedList leftLinkedList = flattenList(root->left);
			leftLinkedList.tail->right = root;

			ll.head = leftLinkedList.head;
			ll.tail = root;
		}
	else if(root->left == NULL && root->right != NULL){
		LinkedList righttLinkedList = flattenList(root->right);
			root->right = righttLinkedList.head;

			ll.head = root;
			ll.tail = righttLinkedList.tail;
	}	
	else{
			LinkedList leftLinkedList = flattenList(root->left);
			LinkedList righttLinkedList = flattenList(root->right);

			leftLinkedList.tail->right = root;
			root->right = righttLinkedList.head;

			ll.head = leftLinkedList.head;
			ll.tail = righttLinkedList.tail;
	}
	return ll;
}

int main() {
	Node * root = NULL;
	// int d ;
	// cin >> d;
	// while (d != -1) {
	// 	root = insert(root, d);
	// 	cin >> d;
	// }
	buildLevelTree(root);
	// printPreorder(root);
	// int arr[] = {1,2,3,4,5,6,7,8,9};
	// int n =  sizeof(arr)/sizeof(arr[0]);

	// root = buildBalanceTree(arr,root,n);
	// cout << endl;
	printByLevelQueue(root);
	// cout << endl;
	// balBst broot = isBalanced(root);
	// cout << broot.height << " " << broot.balance << " ";
	// Node* ans = printAncestor(root,1,2);
	bool bstRoot = is_Bst(root, INT_MAX, INT_MIN);
	cout << "ans = " << bstRoot ;
	return 0;
}