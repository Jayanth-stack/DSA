#include <iostream>
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

void traverse(Node* head){
     Node* temp = head;
     while(temp!= NULL){
        cout<<temp->value<<"->";
        temp = temp->next;
     }cout<< "NULL" <<endl;
}

void insertAtHead(Node* head, int val){
    Node* newnode = new Node(val);
    newnode->next = head;
    head = newnode;
}

void insertAtEnd(Node* &head, int val){
    Node* newnode = new Node(val);
    if(head == NULL){
        head = newnode;
        return;
    }
    
    Node* temp = head;
    while(temp->next != NULL){
        temp =  temp->next;
    }
    temp->next = newnode;
}

int findMiddleNode(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next != NULL){
        slow =  slow->next;
        fast = fast->next->next;

    }

    return slow->value;
}


int main(){
    Node* head = NULL; 
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);

    traverse(head);
    cout<<findMiddleNode(head)<<endl;

    return 0;
}