// Delete the Middle Node of the Linked List

#include <iostream>
using namespace std;

struct Node{
     int data;
     Node* next;
     Node(int val){
          data = val;
          next = nullptr;
     }
};
Node* insertValues(Node* head , int value){
    Node* newNode = new Node(value);
    if(head==nullptr){
        return newNode;
    }
    else{
        Node* temp = head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
    temp->next=newNode;
    return head;
    }
}

void priintList(Node* head){
    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

Node* findmiddlenode(Node* head){
     if(head == nullptr || head->next == nullptr){
          return head;
     }
     Node* slow = head;
     Node* fast = head;
     while(fast != nullptr && fast->next != nullptr){
          slow = slow->next;
          fast = fast->next->next;

     }
     return slow;
}

Node* deleteMiddle(Node* head){
    if(head == nullptr || head->next == nullptr){
        return nullptr;
    }
    Node* middle = findmiddlenode(head);
    Node* temp = head;
    while(temp->next != middle){
        temp = temp->next;
    }
    temp->next = middle->next;
    delete middle;
    return head;
}

int main(){
    int len;
    cin>>len;
    Node* head = nullptr;
    for(int i=0;i<len;i++){
        int value;
        cin>>value;
        head = insertValues(head , value);
    }
    cout<<"Original List: "<<endl;
    priintList(head);
    head = deleteMiddle(head);
    cout<<endl<<"List after deleting middle node: "<<endl;
    priintList(head);
    return 0;

}