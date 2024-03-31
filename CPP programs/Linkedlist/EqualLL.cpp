#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int v) {
        value = v;
        next = NULL;
    }
};

void traverse(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->value << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
} // Missing bracket was added here

void insertAtHead(Node* &head, int val) {
    Node* newnode = new Node(val);
    newnode->next = head; // Corrected from newnode->head = head;
    head = newnode;
}

void insertAtEnd(Node* &head, int val) {
    Node* newnode = new Node(val);
    if(head == NULL) {
        head = newnode; // Corrected from head == newnode;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

bool checkEqualNode(Node* node1, Node* node2) {
    while(node1 && node2) { // Corrected parameter names
        if(node1->value != node2->value) {
            return false;
        }
        node1 = node1->next;
        node2 = node2->next;
    }
    return (node1 == NULL && node2 == NULL); // Corrected parameter names
}
void reverseLL(Node* &head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next;

    while (curr){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}
int main() {
    Node* head = NULL;
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);

    traverse(head);

    reverseLL(head);

    traverse(head);

    //cout << checkEqualNode(head1, head2) << endl;
    return 0;
}
