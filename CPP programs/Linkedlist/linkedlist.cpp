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

void traverse (Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->value<<"->";
        temp = temp->next;
    }cout<< "NULL" <<endl;

}

void insertAtHead(Node* &head, int val){
  Node* newnode = new Node(val);
  newnode->next = head;
  head = newnode;
}

void insertAtEnd(Node* &head, int val){
  if(head==NULL){
    insertAtEnd (head, val);
    return;
  }
  Node* newnode = new Node(val);
  Node* temp = head;
  while(temp->next!=NULL){
    temp = temp->next;
  }
  temp->next = newnode;
}
void insertAtMiddle(Node* &head, int val, int position){
  if(position ==1){
    insertAtHead(head, val);
    return;
  }
   Node* newnode = new Node(val);
   Node* prev = head;
   int count =1;
   while(count < (position -1)){
    prev = prev-> next;
    count++;}

    newnode->next = prev->next;
    prev->next = newnode;


}

void deleteAtHead(Node* &head){
  if(head==NULL){
    return;
  }
  Node* temp = head;
  head = head->next;
  free(temp);
}

void deleteAtEnd(Node* &head){
  if(head==NULL){
    return;

  }
  if(head->next==NULL){
    return;
  }
  
  Node* secondLastNode = head;
  while(secondLastNode->next->next!= NULL){
    secondLastNode = secondLastNode->next;

  }
  Node* lastNode = secondLastNode->next;
  secondLastNode->next = NULL;
  free(lastNode);
}

void deleteAtMiddle(Node* &head, int position){
  if(position ==1){
    deleteAtHead(head);
    return;
  }
   Node* prev = head;
   int count =1;
   while(count <(position -1)){
    prev = prev->next;
    count++;
   }
   Node* curr = prev->next;
   prev->next = curr->next;
   free(curr);
}

void updatedNodeValue(Node* &head, int k, int updatedValue){
  Node* temp = head;
  int count =1;
  while(count <k) {
    temp = temp -> next;
    count++;
  }
  temp->value = updatedValue;
}


int main(){

    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    node1-> next = node2;

    Node* head = node1;
    traverse(head);
    insertAtHead(head, 4);
    traverse(head);
    insertAtEnd(head, 7);
    traverse(head);
    insertAtMiddle(head, 2, 4);
    traverse(head);
    deleteAtHead(head);
    traverse(head);
    deleteAtEnd(head);
    traverse(head);
    deleteAtMiddle(head, 2);
    traverse (head);
    updatedNodeValue(head, 1, 7);
    traverse(head);
    return 0;
}

