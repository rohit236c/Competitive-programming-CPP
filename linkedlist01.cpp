#include<iostream>
using namespace std;

class node {
public:
	int data;
	node*next;
	node(int d) {
		data = d;
		next = NULL;
	}
};
void create(node*&head, int data) {
	node *n = new node(data);
	n -> next = head;
	head = n;
}

void insertatmid(node*head, int data, int pos) {
	if (head == NULL || pos == 1) {
		create(head, data);
	}
	else {
		node*ptr = head;
		node*prev;
		int cnt = 1;
		while (cnt < pos) {
			prev = ptr;
			ptr = ptr->next;
			cnt++;
		}
		node*n = new node(data);
		n->next = prev->next;
		prev->next = n;
	}
}
void insertatend(node*&head, int data) {

	if (head == NULL) {
		node*n = new node(data);
		head = n;
	}
	else {
		node*temp = head;
		while (temp->next != NULL) {
			temp = temp->next;

		}		temp->next = new node(data);

	}
}
void insert(node*&head) {
	int data;
	cin >> data;
	node *n = new node(data);
	head = n;
	node*ptr = head;
	cin >> data;
	while (data != -1) {
		insertatend(head, data);
		cin >> data;
	}

}
void circularlinkedlist(node*head) {
	if (head == NULL) {
		return;
	}
	else {
		node*ptr = head;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = head;
	}

}
void print(node*head) {
	node*temp = head;
do {
	    cout << temp->data << "->";
		temp = temp->next;
	} while (temp != head);
	cout << endl;
}


void print1(node*head) {
	while (head) {
		cout << head->data << "->";
		head = head->next;
	}
}


bool detectcycle(node*head) {
	node*slow = head;
	node*fast = head;
	while ( fast != NULL && fast->next != NULL ) {
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow) {
			return true;
		}
	}
	return false;
}
int main() {
	node*head = NULL;
	cout << "ENTER THE ELEMENTS IN circularlinkedlist " << endl;
	insert(head);
	circularlinkedlist(head);
	cout << "ELEMENTS of circularlinkedlist is" << endl;

	print(head);
	// print1(head);

}