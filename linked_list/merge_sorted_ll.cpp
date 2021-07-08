#include <iostream>
using namespace std;

struct node {
	int data;
	node * next;
};

node * mergeLL(node * head1, node * head2) {
	node * head = new node();

	if(head1->data > head2->data) {
		head->data = head2->data;
		head2 = head2->next;
	} else {
		head->data = head1->data;
		head1 = head1->next;
	}

	cout<<head->data<<endl;
 	node * t = head;
	while(head1 != NULL && head2 != NULL) {
		node * temp = new node();
		if(head1->data > head2->data) {
			temp->data = head2->data;
			head2 = head2->next;
		} else {
			temp->data = head1->data;
			head1 = head1->next;
		}
		t->next = temp;
		t = t->next;
	}

	if(head1 != NULL) {
		node * temp = head;
		while(temp != NULL) {
			temp = temp->next;
		}
		while(head1 != NULL) {
			node * newNode = new node();
			newNode->data = head1->data;
			head1 = head1->next;
		}
	}
	if(head2 != NULL) {
		node * temp = head;
		while(temp != NULL) {
			temp = temp->next;
		}
		while(head2 != NULL) {
			node * newNode = new node();
			newNode->data = head1->data;
			head2 = head2->next;
		}
	}
	return head;
}

node * createLL(int a[], int n) {
    node * head = new node();
    head->data = a[0];
    node * temp = head;
    for(int i = 1; i < n; i++) {
        node * newNode = new node();
        newNode->data = a[i];
        temp->next = newNode;
        temp = temp->next;
    }
    return head;
}

void display(node * head) {
	while(head != NULL) {
		cout<<head->data<<" ";
		head = head->next;
	}
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		int a, b;
		cin>>a;
		int c[a];
		for(int i = 0; i < a; i++) {
			cin>>c[i];
		}
		cin>>b;
		int d[b];
		for (int i = 0; i < b; i++)	{
			cin>>d[i];
		}
		node * headA = createLL(c, a);
		node * headB = createLL(d, b);
		node * head = mergeLL(headA, headB);
		display(head);
	}
	
	return 0;
}