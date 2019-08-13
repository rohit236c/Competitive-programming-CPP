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
	n->left = buildTree();
	n->right = buildTree();
	return n;
}
void buildLevelTree(Tree * &root) {
	int data;
	cin >> data;
	root = new Tree(data);
	queue<Tree *>q;
	q.push(root);
	while (!q.empty()) {
		Tree * n = q.front();
		q.pop();
		int d1, d2;
		cin >> d1 >> d2;
		if (d1 != -1) {
			n -> left = new Tree(d1);
			q.push(n->left);
		}
		if (d2 != -1) {
			n -> right = new Tree(d2);
			q.push(n->right);
		}
	}
}
void preOrder(Tree * root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << " ,";
	preOrder(root->left);
	preOrder(root->right);
}
void inOrder(Tree * root) {
	if (root == NULL) {
		return;
	}
	inOrder(root->left);
	cout << root->data << " ,";
	inOrder(root->right);
}
void postOrder(Tree * root) {
	if (root == NULL) {
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " ,";
}
void printLevel(Tree * root, int k) {
	if (root == NULL) {
		return;
	}
	if (k == 0) {
		cout << root->data << " ";
	}
	printLevel(root->left, k - 1);
	printLevel(root->right, k - 1);
}
int height( Tree * root) {
	if (root == NULL) {
		return 0;
	}
	int leftHeight = height(root->left);
	int rightHeight = height(root->right);
	return max(leftHeight, rightHeight) + 1;
}
void printByLevel(Tree * root) {
	if (root == NULL) {
		return;
	}
	int minLevel = 0;
	int depth = height(root);
	for (int i = 0; i <= depth; i++) {
		printLevel(root, i);
		cout << endl;
	}
}
void printByLevelQueue(Tree * root) {
	queue<Tree *>q;
	q.push(root);
	q.push(NULL);
	while (!q.empty()) {
		Tree * front = q.front();
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
class sumPair {
public:
	int inc;
	int exc;
};
sumPair maxSubSum(Tree * root) {
	sumPair p;
	if (root == NULL) {
		p.inc = 0;
		p.exc = 0;
		return p;
	}
 
	sumPair leftSubSum = maxSubSum(root->left);
	sumPair rightSubSum = maxSubSum(root->right);

	p.inc = root->data + leftSubSum.exc + rightSubSum.exc;
	p.exc = max(leftSubSum.inc, leftSubSum.exc) + max(rightSubSum.inc, rightSubSum.exc);

	return p;
}
int main() {
	Tree*root = NULL;
	// root = buildTree();
	buildLevelTree(root);
	printByLevelQueue(root);
	// printByLevel(root);
	// preOrder(root);
	// inOrder(root);
	cout << endl;
	cout << "maxSubSum is = ";
	sumPair ans = maxSubSum(root);
	int finalAns = max(ans.inc, ans.exc);
	cout <<finalAns<< "";
	return 0;
}
/*
5 6 7 -1 -1 -1 8 9 -1 -1 10 -1 -1
*/