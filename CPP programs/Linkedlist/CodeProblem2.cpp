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

//checking for palindrome

bool checkforPalindrome(Node* head){

    if(head->next = NULL){
        return true;
    }

    // find the middle node 

    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;

    }

    //2. reverse the second half of  linkedlist

    Node* curr = slow;
    Node* prev = NULL;
    Node* next;

    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;

    }

    //3. comparing the two halfs

    Node* head2 = prev;
    while(head2){
        if(head->value!=head2->value){
            return false;
        }
        head = head->next;
        head2 = head2->next;
    }

    return true;
}


int main(){

    Node* head = NULL;

    insertAtEnd(head,1);
    insertAtEnd(head,4);
    insertAtEnd(head,3);
    insertAtEnd(head,3);
    insertAtEnd(head,2);
    insertAtEnd(head,4);

    traverse(head);
    cout<<checkforPalindrome(head)<<endl;

    return 0;
}