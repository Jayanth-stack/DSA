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
    while(temp!=NULL){
        cout<<temp->value<<"->";
        temp = temp->next;
    }cout<<"NULL"<<endl;
}
void insertAtHead(Node* &head, int val){
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(Node* &head, int val){
    Node* newNode = new Node(val);
    if(head == NULL){
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp ->next;
    }
    temp->next = newNode;
}

Node* MergeandSort(Node* head1, Node* head2){

    Node* dummyNode = new Node(-1);
    Node* head3 = dummyNode;

    while(head1 && head2){
        if(head1->next < head2->next){
            head3->next = head1;
            head1 = head1->next;
        }
        else{
            head3->next = head2;
            head2 = head2->next;
        }
        head3 =  head3->next;
    }

    if(head1){
        head3->next =  head1;

    }
    if(head2){
        head3->next = head2;
    }

    return dummyNode->next;

}

int main(){
    Node* head1 = NULL;
    insertAtEnd(head1, 1);
    insertAtEnd(head1, 4);
    insertAtEnd(head1, 5);
    insertAtEnd(head1, 7);

    Node* head2 = NULL;

    insertAtEnd(head2, 2);
    insertAtEnd(head2, 3);
    insertAtEnd(head2, 6);

    traverse(head1);
    traverse(head2);
    traverse(MergeandSort(head1, head2));

    return 0;
}