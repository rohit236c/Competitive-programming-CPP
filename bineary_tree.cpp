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
	for (int i = depth; i >= 0; i--) {
		printLevel(root, i);
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

void spiralPrint(Tree* root) {
//maintain a level count 

	//if odd push leftchild && then push right child

	//else push rightchild && push leftchild
}
void reverseLevelOrder(Tree*root){
	//reverse the level of order of printing.....

	//1. first approach use dequeue...
	//2. using recursion and for loop
	//3. using queue + stack in this method
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
int sumLeaf(Tree * root) {
	if (root == NULL) {
		return 0;
	}
	if (root->left == NULL && root->right == NULL) {
		return root->data;
	}
	int leftSum = sumLeaf(root->left);
	int rightSum = sumLeaf(root->right);

	return leftSum + rightSum ;
}
void printSibling(Tree * root) {
	if (root == NULL) {
		return;
	}
	if (root->left == NULL && root->right) {
		cout << root->right->data << " ";
	}
	if (root->right == NULL && root->left) {
		cout << root->left->data << " ";
	}
	printSibling(root->left);
	printSibling(root->right);
}
bool sumTree(Tree * root) {
	if (root == NULL) {
		return true;
	}
	if (root->left == NULL || root->right == NULL) {
		return false;
	}

	sumTree(root->left);
	sumTree(root->right);
	if (root->data != (root->left->data + root->right->data)) {
		return false;
	}

	return true;
}
bool printAncestor(Tree * root, int key) {
	if (root == NULL)
		return false;
	if (root->data == key)
		return true;

	if ( printAncestor(root->left, key) ||
	        printAncestor(root->right, key) )
	{
		cout << root->data ;
		return true;
	}

	return false;
}
class rootHD {
public:
	int hd;
	Tree* node;
};
void verticalPrint(Tree * root) {
	queue<rootHD>q;
	multimap<int, Tree * >mymap;
	if (root == NULL) {
		return;
	}
	int hd = 0;
	rootHD r;
	r.hd = 0;
	r.node = root;
	q.push(r);
	mymap.insert(pair<int, Tree*>(hd, root));
	while (!q.empty()) {
		rootHD front = q.front();
		q.pop();

		if (front.node->left != NULL) {
			rootHD temp;
			temp.hd = front.hd - 1;
			temp.node = front.node->left;
			q.push(temp);
			mymap.insert(pair<int, Tree*>(temp.hd, front.node->left));
			// mymap[hd-1] = front->left->data;
		}
		if (front.node->right != NULL) {
			rootHD temp1;
			temp1.hd = front.hd + 1;
			temp1.node = front.node->right;
			q.push(temp1);
			mymap.insert(pair<int, Tree*>(temp1.hd, front.node->right));
		}
	}
	for (auto i = mymap.begin(); i != mymap.end(); ++i) {
		cout << i->first << " " << i->second->data << endl;
	}
}
void topLevel(Tree * root) {
	queue<rootHD>q;
	multimap<int, Tree * >mymap;
	if (root == NULL) {
		return;
	}
	int hd = 0;
	rootHD r;
	r.hd = 0;
	r.node = root;
	q.push(r);
	mymap.insert(pair<int, Tree*>(hd, root));
	while (!q.empty()) {
		rootHD front = q.front();
		q.pop();

		if (front.node->left != NULL) {
			rootHD temp;
			temp.hd = front.hd - 1;
			temp.node = front.node->left;
			cout << "temp hd " << temp.hd << endl;
			auto itr = mymap.find(temp.hd);
			if (itr == mymap.end()) {
				cout << temp.hd << " " << temp.node->data << " " << endl;
				mymap.insert(pair<int, Tree*>(temp.hd, front.node->left));
			}
			q.push(temp);

			// mymap[hd-1] = front->left->data;
		}
		if (front.node->right != NULL) {
			rootHD temp1;
			temp1.hd = front.hd + 1;
			temp1.node = front.node->right;
			cout << "temp1 hd " << temp1.hd << endl;
			auto itr = mymap.find(temp1.hd);
			auto itr2 = mymap.find(2);

			if (itr == mymap.end()) {
				cout << temp1.hd << " " << temp1.node->data << " " << endl;
				mymap.insert(pair<int, Tree*>(temp1.hd, front.node->right));
			}
			q.push(temp1);
		}
	}
	cout << "finalAns = ";
	for (auto i = mymap.begin(); i != mymap.end(); ++i) {
		cout << i->second->data << " ";
	}

}

int main() {
	Tree*root = NULL;
	// root = buildTree();
	buildLevelTree(root);
	// printByLevelQueue(root);
	printByLevel(root);
	// cout << endl;
	// verticalPrint(root);
	// topLevel(root);
	// printByLevel(root);
	// preOrder(root);
	// inOrder(root);
	// printSibling(root);
	// cout << sumTree(root);
	// cout << "maxSubSum is = ";
	// printAncestor(root,0);
	// sumPair ans = maxSubSum(root);
	// int finalAns = max(ans.inc, ans.exc);
	// cout <<finalAns<< "";
	// cout<<"sum = "<< sumLeaf(root);
	return 0;
}