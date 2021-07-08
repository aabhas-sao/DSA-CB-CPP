#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

// This function gets two arguments - the head pointers of the two linked lists
// Return the node which is the intersection point of these linked lists
// It is assured that the two lists intersect
Node *intersectionOfTwoLinkedLists(Node *l1, Node *l2)
{
    Node * temp1 = l1;
    Node * temp2 = l2;
    int c1 = 0;
    int c2 = 0;
    
    // find length of both linked lists
    
    while(temp1 != NULL) {
        c1++;
        temp1 = temp1->next;
    }

    while(temp2 != NULL) {
        c2++;
        temp2 = temp2->next;
    }

    int diff = c2 - c1;

    if(diff >= 0) {
        while(diff--) {
            l2 = l2->next;
        }
    }
    else {
        diff = -1 * diff;
        while(diff--) {
            l1 = l1->next;
        }
    }

    while(l1 != NULL && l2 != NULL && l1->data != l2->data) {
        l1 = l1->next;
        l2 = l2->next;
    }
    
    return l1;
}



/*
*
*
*   You do not need to refer or modify any code below this. 
*   Only modify the above function definition.
*	Any modications to code below could lead to a 'Wrong Answer' verdict despite above code being correct.
*	You do not even need to read or know about the code below.
*
*
*
*/

Node *buildList(unordered_map<int, Node *> &hash)
{
    int x;
    cin >> x;
    Node *head = new Node(x);
    Node *current = head;
    hash[x] = head;
    while (x != -1)
    {
        cin >> x;
        if (x == -1)
            break;
        Node *n = new Node(x);
        hash[x] = n;
        current->next = n;
        current = n;
    }
    current->next = NULL;
    return head;
}

void printLinkedList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // unordered_map<int, Node *> hash;
    // Node *l1 = buildList(hash);

    // Node *l2 = NULL;
    // int x;
    // cin >> x;
    // l2 = new Node(x);
    // Node *temp = l2;

    // while (x != -1)
    // {
    //     cin >> x;
    //     if (x == -1)
    //         break;
    //     if (hash.find(x) != hash.end())
    //     {
    //         temp->next = hash[x];
    //         break;
    //     }
    //     Node *n = new Node(x);
    //     temp->next = n;
    //     temp = n;
    // }

    // cout << "L1 - ";
    // printLinkedList(l1);
    // cout << "L2 - ";
    // printLinkedList(l2);

    // Node *intersectionPoint = intersectionOfTwoLinkedLists(l1, l2);
    // cout << "Intersection at node with data = " << intersectionPoint->data << endl;

    Node * head1 = new Node(1);
    Node * l1 = head1;
    l1->next = new Node(7);
    l1 = l1->next;
    l1->next = new Node(2);
    l1 = l1->next;
    Node * n2 = l1;
    l1->next = new Node(3);

    Node * l2 = new Node(4);
    l2->next = n2;
    // cout<<1;
    Node * ans = intersectionOfTwoLinkedLists(head1, l2);
    cout<<ans->data<<endl;
    printLinkedList(head1);
    printLinkedList(l2);
    return 0;
}