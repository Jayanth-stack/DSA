#include<iostream>
using namespace std;


class Node{
    public:
    int value;
    Node* next;

    Node(int v){
        value = v;
        next = NULL;
    }
};

void traverse (Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->value<<"->";
        temp = temp->next;
    }cout<<"NULL"<<endl;
}

void insertAtHead(Node* &head, int val){
    Node* newnode = new Node(val);
    newnode->next = head;
    head = newnode;
}

void insertAtEnd(Node* &head, int val){
    Node* newnode = new Node(val);
    while(head == NULL){
        head = newnode;
        return;
    }
    Node* temp = head;
    while(temp->next!= NULL){
        temp = temp ->next;

    }temp->next = newnode;
}

void RotateLinkedlist(Node* &head, int k){
    Node* temp = head;
    int n =1;
    while(temp->next){
        n++;
        temp = temp->next;
    }
    k = k%n;
    while(k == 0){
        return;
    }

    temp->next = head;

    temp = head;
    for(int i=1;i<(n-k);i++){
        temp = temp->next;
    }
    Node* newHead = temp->next;
    temp->next = NULL;

    head = newHead;
}

int main(){
    Node* head = NULL;

    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);
    insertAtEnd(head, 6);
    
    traverse(head);
    RotateLinkedlist(head, 4);
    traverse(head);

    return 0;
}